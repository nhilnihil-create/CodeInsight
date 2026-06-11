#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
#define ALL(a)  (a).begin(),(a).end()
const ll INF = 1e18+18;
const ll MAX = 200000;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
static const double pi = 3.141592653589793;



int main(){
    ll N;
    cin>>N;
    ll P, W, G, Y;
    P=0;
    W=0;
    G=0;
    Y=0;
    vector<char> S(N);
    rep(i, N){
        cin>>S[i];
        if(S[i]=='P')P++;
        if(S[i]=='W')W++;
        if(S[i]=='G')G++;
        if(S[i]=='Y')Y++;
    }
    ll Ans=0;
    if(P)Ans++;
    if(W)Ans++;
    if(G)Ans++;
    if(Y)Ans++;
    if(Ans==3)cout<<"Three"<<endl;
    if(Ans==4)cout<<"Four"<<endl;
}