#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define rrep(i,n) for(int i=int(n-1);i>=0;i--)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;
ll const mod=998244353;
const ll MAX=300000;
using vi=vector<int>;
using vc=vector<char>;
using vd=vector<double>;
using vs=vector<string>;
using vp=vector<P>;
using vb=vector<bool>;
using vvi =vector<vector<int>>;
using vvd=vector<vector<double>>;
using vvc=vector<vector<char>>;
using vvp =vector<vector<P>>;
using vvb=vector<vector<bool>>;
template <typename T>
bool chmax(T &a, const T b){if(a < b){a = b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T b){if(a > b){a = b; return true;} return false;}


//////////////////////////////////////
struct cake {
    ll a;
    ll b;
    ll c;
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<cake>x(n);
    vector<ll>sum(n);
    ll ans=0;
    rep(i,n){
        cin>>x[i].a>>x[i].b>>x[i].c;
        sum[i]=(x[i].a+x[i].b+x[i].c);
    }
    sort(all(sum),greater<ll>());
    ll tmp=0;
    rep(i,m){
        tmp+=sum[i];
    }
    chmax(ans,tmp);
    

    rep(i,n){
        
        sum[i]=(x[i].a+x[i].b-x[i].c);
    }
    sort(all(sum),greater<ll>());
    tmp=0;
    rep(i,m){
        tmp+=sum[i];
    }
    chmax(ans,tmp);
    rep(i,n){
        
        sum[i]=(x[i].a-x[i].b+x[i].c);
    }
    sort(all(sum),greater<ll>());
    tmp=0;
    rep(i,m){
        tmp+=sum[i];
    }
    chmax(ans,tmp);
    rep(i,n){
        
        sum[i]=(-x[i].a+x[i].b+x[i].c);
    }
    sort(all(sum),greater<ll>());
    tmp=0;
    rep(i,m){
        tmp+=sum[i];
    }
    chmax(ans,tmp);
    rep(i,n){
        
        sum[i]=(-x[i].a-x[i].b+x[i].c);
    }
    sort(all(sum),greater<ll>());
    tmp=0;
    rep(i,m){
        tmp+=sum[i];
    }
    chmax(ans,tmp);
    rep(i,n){
        
        sum[i]=(x[i].a-x[i].b-x[i].c);
    }
    sort(all(sum),greater<ll>());
    tmp=0;
    rep(i,m){
        tmp+=sum[i];
    }
    chmax(ans,tmp);
    rep(i,n){
        
        sum[i]=(-x[i].a+x[i].b-x[i].c);
    }
    sort(all(sum),greater<ll>());
    tmp=0;
    rep(i,m){
        tmp+=sum[i];
    }
    chmax(ans,tmp);


    rep(i,n){
        
        sum[i]=(-x[i].a-x[i].b-x[i].c);
    }
    sort(all(sum),greater<ll>());
    tmp=0;
    rep(i,m){
        tmp+=sum[i];
    }
    chmax(ans,tmp);


    cout<<ans<<endl;
    return 0;
}