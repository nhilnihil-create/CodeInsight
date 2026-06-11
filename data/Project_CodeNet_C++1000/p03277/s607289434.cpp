#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<typename T>
struct BIT{
    //1-index
    //0-indexで取ると無限ループする
    private:
    V<T> arr;
    int n;

    public:
    BIT(int siz){
        n=siz;
        arr.assign(n+1,0);
    }
    //一点更新 aにvを加える
    void add(T a,T v){
        //x+=(x&-x) 初項a,それ以降a<=2^Nが列挙
        for(T x=a;x<=n;x+=(x&-x)){
            arr[x]+=v;
        }
    }
    T sum(T a){
        // 1からaまでの区間和
        T ret=0;
        for(T x=a;x>0;x-=(x&-x))ret+=arr[x];
        return ret;
    }
    T lower_bound(T w){// 区間和がw以上となる最小のindを返す
        if(w<=0)return 0;
        T x,r=1;//xは横の位置,rはrank
        while(r<n)r<<=1;
        for(T k=r;k>0;k>>=1){
            if(x+k<=n&&arr[x+r]<w){
                w-=arr[x+r];
                x+=k;
            }
        }
        return x+1;
    }
    T get(T x){//x番目に大きい数
        if(x<=0) return 0;
        T N=1;
        while(N*2<=n)N*=2;
        T v=0;
        for(T i=N;i>0;i/=2){
            if(v+i<=n&&arr[v+i]<x){
                x-=arr[v+i];
                v+=i;
            }
        }
        return v+1;
    }
    T query(int l,int r){
        return sum(r)-sum(l);
    }
};
ll n;
V<ll> a;
V<ll> sum;
V<P> dat;
ll solve(ll x){
    BIT<ll> bit(n+1);
    sum.assign(n+1,0);
    dat.clear();
    for(int i=0;i<n;i++){
        ll add;
        if(a[i]>=x)add=1;
        else add=-1;
        sum[i+1]=sum[i]+add;
    }
    for(int i=0;i<=n;i++)dat.emplace_back(sum[i],i);
    sort(all(dat),greater<P>());
    ll res=0;
    for(int i=0;i<=n;){
        int j=i;
        while(j<=n&&dat[i].fi==dat[j].fi){
            res+=bit.sum(dat[j].se);
            j++;
        }
        j=i;
        while(j<=n&&dat[i].fi==dat[j].fi){
            bit.add(dat[j].se+1,1);
            j++;
        }
        i=j;
    }
    return res;
}
int main(){
    cin>>n;
    a.resize(n);
    V<ll> d(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll l=0,r=(1e10);
    while(r-l>1){
        ll mid=(l+r)/2;
        ll c=solve(mid);
        if(c>(n+1)*n/2/2)r=mid;
        else l=mid;
    }
    cout<<r-1<<"\n";
}