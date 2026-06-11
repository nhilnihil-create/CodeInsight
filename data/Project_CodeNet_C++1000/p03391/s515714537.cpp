#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int main(){
    ll N;
    cin >> N;
    ll sum = 0;
    vector<ll> A(N);
    vector<ll> B(N);
    bool same = true;
    REP(i,N){
        ll a, b;
        cin >> a >> b;
        A[i] = a;
        B[i] = b;
        if(a != b) same = false;
        sum += a;
    }

    if(same){
        cout << 0 << endl;
        return 0;
    }

    ll ans = LLONG_MAX;
    REP(i,N){
        ll a, b;
        a = A[i];
        b = B[i];
        if(a > b){
            chmin(ans, b);
        }
    }

    ans = sum - ans;
    cout << ans << endl;
    return 0;
}
