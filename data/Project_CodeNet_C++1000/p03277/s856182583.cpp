#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
template<class T>void chmax(T &a,T b){if(a<b)a=b;}
template<class T>void chmin(T &a,T b){if(a>b)a=b;}
constexpr int INF=1000000000000000000;
constexpr int mod=1000000007;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int kaijo[2000010];
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
bool prime(int a){
    if(a==1)return false;
    for(int i=2;i*i<=a;i++){
        if(a%i==0)return false;
    }
    return true;
}
void init_fact(){
    kaijo[0]=1;
    for(int i=1;i<=2000000;i++){
        kaijo[i]=kaijo[i-1]*i;
        kaijo[i]%=mod;
    }
}
int modpow(int a,int b){
    if(b==0)return 1;
    if(b%2)return modpow(a,b-1)*a%mod;
    int memo=modpow(a,b/2);
    return memo*memo%mod;
}
int comb(int a,int b){
    if(!kaijo[0])init_fact();
    return kaijo[a]*modpow(kaijo[a-b],mod-2)%mod*modpow(kaijo[b],mod-2)%mod;
}
int inv(int x){
    x=modpow(x,mod-2);
    return x;
}
bool kosa(double ax,double ay,double bx,double by,double cx,double cy,double dx,double dy){
    double ta=(cx-dx)*(ay-cy)+(cy-dy)*(cx-ax);
    double tb=(cx-dx)*(by-cy)+(cy-dy)*(cx-bx);
    double tc=(ax-bx)*(cy-ay)+(ay-by)*(ax-cx);
    double td=(ax-bx)*(dy-ay)+(ay-by)*(ax-dx);
    return tc*td<0&&ta*tb<0;
}
struct BIT{
    int n;
    vector<int>bit;
    BIT(int x){
        bit.resize(x,0);
        n=x;
    }
    int sum(int i){
        int res=0;
        while(i>0){
            res+=bit[i];
            i-=i&-i;
        }
        return res;
    }
    void add(int i,int x){
        while(i<n){
            bit[i]+=x;
            i+=i&-i;
        }
    }
};
int n,a[100010];
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,n)cin>>a[i];
    int l=(n+1)*n/2/2;
    if(n%4==1||n%4==2)l++;
    int ok=0,ng=1000000001;
    while(ng-ok>1){
        int x=(ok+ng)/2;
        vector<int>v(n+1);
        v[0]=0;
        rep(i,n){
            if(a[i]>=x)v[i+1]=1;
            else v[i+1]=-1;
        }
        for(int i=1;i<=n;i++)v[i]+=v[i-1];
        rep(i,n+1)v[i]+=n+1;
        BIT bit(2*n+5);
        bit.add(v[0],1);
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=bit.sum(v[i]);
            bit.add(v[i],1);
        }
        if(sum>=l)ok=x;
        else ng=x;
    }
    cout<<ok<<endl;
	return 0;
}
