#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int main(){
    int N;
    cin >> N;
    vector<int> C;
    int last = -1;
    REP(i,N){
        int c;
        cin >> c;
        if(c != last)
            C.push_back(c);
        last = c;
    }

    int L = C.size();
    map<int, ll> X;
    vector<ll> DP(L+1);
    set<int> A;

    ll ans = 0;
    DP[0] = 1;
    REP(i,L){
        int c = C[i];

        A.insert(c);
        DP[i+1] = DP[i] + X[c];
        DP[i+1] %= MOD;
        //X[c] += DP[i] + 1;
        X[c] += DP[i];
        X[c] %= MOD;
    }

    ans = DP[L] % MOD;
    //ans += 1;
    cout << ans << endl;
    return 0;
}
