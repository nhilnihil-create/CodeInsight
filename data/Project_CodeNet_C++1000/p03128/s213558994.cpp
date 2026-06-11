#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin(), v.end()
bool chmin(ll & a, ll  b) { if (b < a) { a = b; return 1; } return 0; }
bool chmax(ll & a, ll b) { if (b > a) { a = b; return 1; } return 0; }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N=500010;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
bool lamda(string S,string T){
    if(S.length()>T.length())return true;
    if(S.length()<T.length())return false;
    if(S>T)return true;
    return false;
}
int main() {
    ll A[9]={2,5,5,4,5,6,3,7,6};
    cin>>n>>m;
    vl ok(9,0);
    rep(i,m){
        cin>>x;
        ok[x-1]=1;
    }

    vector<string> V;
    string S;

    rep(i,n+1){
        if(i==0)V.push_back("");
        else V.push_back("!");
        rep(j,9){
            if(ok[j]==1&&i>=A[j]&&V[i-A[j]]!="!"){
                S=V[i-A[j]];
                char c='1'+j;
                S=S+c;
                if(lamda(S,V[i]))V[i]=S;
            }
        }
    }

    cout<<V[n]<<endl;
}
