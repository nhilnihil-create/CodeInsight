#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

int main(){
    ll N;
    string S;
    cin >> N >> S;
    vector<ll> RB(N+1), LW(N+1);
    rep(i,N){
        RB[i+1] = RB[i] + ll(S[i] == '#');
        LW[N-1-i] = LW[N-i] + ll(S[N-1-i] == '.');
    }
    ll m=1e18;
    rep(i,N+1){
        cmin(m,RB[i] + LW[i]);
    }
    cout << m << endl;
}
