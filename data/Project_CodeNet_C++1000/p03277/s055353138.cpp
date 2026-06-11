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




 
template<typename T>
struct BinaryIndexedTree{
   vector<T> data;
   BinaryIndexedTree(int sz){
       data.assign(sz+1, 0);
   }
   // 区間[0,k]の合計 sum(v[0]~v[k])
   T sum(int k){
       T ret=0;
       for(++k;k>0;k-=(k&-k)) ret+=data[k];
       return ret;
   }
   // v[a]+=x
   void add(int k,T x){
       for(++k;k<data.size();k+=(k&-k)) data[k]+=x;
   }
   // wを超える最小のv[i]のiを返す(0indexedのを返す)(data上のindexを返したいならreturn x+1)
   int lower_bound(T w){//T?
       if(w<=0) return 0;
       //左右どっちに行くか考える
       int x=0,r=1;
       while(r<data.size()) r<<=1;
       for(int k=r;k>0;k>>=1){
           if(x+k<=data.size()&&data[x+k]<w){
               //左部分を引いて右へ，再起っぽい
               w-=data[x+k];
               x+=k;
           }
       }
       // return x+1;
       return x;
   }
};
 
 
ll g(vector<int> v){
    int n=v.size();
    if(n<=1){
        return 0;
    }
    int vmax=*max_element(ALL(v));
    BinaryIndexedTree<ll> bit(vmax+1);
    ll ret=0;
    rep(i,n){
        ret+=bit.sum(v[i]);
        bit.add(v[i],1);
    }
    return ret;
}



ll n;
vector<ll> a;


//m以上の中央値になるような区間がn(n+1)/4+1以上あるかどうか
bool f(ll m){
    vector<int> pm(n);//+?-?
    rep(i,n){
        if(a[i]<m)  pm[i]=-1;
        else        pm[i]=1;
    }

    vector<int> sum(n+1);
    sum[0]=0;
    rep(i,n) sum[i+1]=sum[i]+pm[i];
    int geta=-(*min_element(ALL(sum)));
    rep(i,n+1) sum[i]+=geta;
    ll k=g(sum);
    // cout<<m<<" : "<<k<<endl;
    return k>=n*(n+1)/4;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin>>n;
    a.resize(n);
    rep(i,n) cin>>a[i];
    if(n==1){
        cout<<a[0]<<endl;
        return 0;
    }

    ll lw=0,hi=LINF,ans=0;
    while(lw<=hi){
        ll mid=(lw+hi)/2;
        if(f(mid)){
            ans=mid;
            lw=mid+1;
        }else{
            hi=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
