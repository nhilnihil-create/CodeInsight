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
int n,t[210],v[210],r[210],ma[40010],now,sum;
signed main(){
    cin>>n;
    rep(i,n){
        cin>>t[i];
        t[i]*=2;
        r[i+1]=r[i]+t[i];
    }
    fill(ma,ma+r[n]+1,INF);
    ma[0]=ma[r[n]]=0;
    rep(i,n){
        cin>>v[i];
        v[i]*=2;
        for(int j=r[i];j<=r[i+1];j++)ma[j]=min(ma[j],v[i]);
    }
    for(int i=40000;i>=0;i--){
        ma[i]=min(ma[i],ma[i+1]+1);
    }
    for(int i=1;i<=r[n];i++){
        int next=min(now+1,ma[i]);
        sum+=(now+next);
        now=next;
    }
    printf("%.12lf\n",(double)sum/8);
    return 0;
}