#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    int N;
    string A,B,C;
    cin >> N >> A >> B >> C;
    int ans=0;
    rep(i,N){
        if (A[i]==B[i]&&B[i]==C[i]) continue;
        if (A[i]!=B[i]&&B[i]!=C[i]&&C[i]!=A[i]) ans+=2;
        else ans+=1;
    }
    cout << ans << endl;
}