#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    ll n;cin >> n;
    vl v={2,5,63,20,30};
    if(n<6){
      rep(i,n)cout << v[i] <<" ";
      cout <<endl;
      return 0;
    }
    set<ll> st;
    ll rap=0,count=1;
    while(n--){
        if(count==0)st.ins(6*rap);
        if(count==1)st.ins(6*rap+2);
        if(count==2)st.ins(6*rap+3);
        if(count==3)st.ins(6*rap+4);
        count++;
        if(count==4)count=0,rap++;
    }
    ll sum=0;
    for(auto p:st)sum+=p;
    if(sum%6==2)st.erase(8),st.ins(6*rap+6);
    if(sum%6==3)st.erase(9),st.ins(6*rap+6);
    if(sum%6==5)st.erase(9),st.ins(6*rap+4);
    for(auto p:st)cout << p <<" ";
    cout << endl;
}