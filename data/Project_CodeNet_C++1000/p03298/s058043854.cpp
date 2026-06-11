#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<string,string> Pss;
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
    string S;
    cin >> N >> S;
    map<Pss,ll> m;
    rep(bit,1<<N){
        string a="",b="";
        rep(i,N){
            if (bit&1<<i) a+=S[i];
            else b+=S[i];
        }
        reverse(b.begin(),b.end());
        ++m[Pss(a,b)];
    }
    ll ans=0;
    rep(bit,1<<N){
        string a="",b="";
        rep(i,N){
            if (bit&1<<i) a+=S[N+i];
            else b+=S[N+i];
        }
        reverse(b.begin(),b.end());
        ans+=m[Pss(b,a)];
    }
    cout << ans << endl;
}