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
    vector<ll> A(N);
    ll minus = 0;
    ll sum = 0;
    REP(i,N){
        ll a;
        cin >> a;
        A[i] = a;
        if(a < 0) minus++;
        sum += abs(a);
    }

    ll ans = 0;

    if(minus % 2 == 0){
        ans = sum;
    }
    else{
        ll rem = 1e15;
        REP(i,N){
            ll a = A[i];
            chmin(rem, abs(a));
        }

        ans = sum - 2*rem;
    }

    cout << ans << endl;
    return 0;
}
