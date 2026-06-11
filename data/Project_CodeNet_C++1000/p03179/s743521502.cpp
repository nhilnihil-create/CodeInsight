#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(auto i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end(); ++it)
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const ll INF = ~(1<<31);
#define fs first
#define sc second
#define pb push_back

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
    return (a % b + b) % b;
}

string s;
ll n;
ll md = 1000000000+7;

vector<ll> MK_PREF(vector<ll> A) {
    vector<ll> T;
    T.pb(0);
    rep(i,0,A.size()) {
        T.pb((T.back() + A[i]) % md);
    }
    return T;
}

int main() {
    cin.sync_with_stdio(false);
    cin >> n >> s;

    vector<ll> DP(n+1,1);
    vector<ll> PREF;
    for(int i = n-2; i >= 0; i--) {
        PREF = MK_PREF(DP);
        vector<ll> NEWDP(n+1,0);
        for(int j = 1; j <= n; j++) {
            int l,r;
            if(s[i] == '>') {
                l = 1;
                r = j;
            } else {
                l = j+1;
                r = i+2;
            }
            NEWDP[j] = (PREF[r+1] - PREF[l] + md) % md;
        }
        DP = NEWDP;
    }





    cout << DP[1] << endl;
    return 0;
}
