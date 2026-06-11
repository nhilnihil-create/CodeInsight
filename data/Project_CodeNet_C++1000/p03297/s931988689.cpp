#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void solve(){
    ll a,b,c,d;cin>>a>>b>>c>>d;
    //いつか限界が来る
    if(b>d){
        cout<<"No"<<endl;
        return ;
    }
    //最初から無理やん
    if(a<b){
        cout<<"No"<<endl;
        return ;
    }
    //b>dをふまえると超余裕
    if(b<=c+1){
        cout<<"Yes"<<endl;
        return ;
    }

    //c<x<bかつx=A+gcd(b,d)となるようなxが存在するか
    ll g=gcd(b,d);
    ll x=b+a%g-g;
    if(x>c){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int q;cin>>q;
    while(q--) solve();
    return 0;
}
