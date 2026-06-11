#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// head

vector<int> a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 1;
    for(int i = 0; i < n; i++) ans *= 3;

    int cnt = 1;
    for(int i = 0; i < n; i++) {
        int a;
        int odd = 0;
        cin >> a;   
        if(a % 2 == 0) {
            odd += 2;
        } else {
            odd += 1;
        }
        cnt *= odd;
    }

    cout << ans - cnt << endl;
    return 0;
}
