#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <assert.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define SZ(x) x.size()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)
#define pi acos(-1)
#define mod 1000000007
#define inf 1000000007
#define ll long long
#define DBG(x) cerr<<(#x)<<"="<<x<<"\n";
#define N 100010
#define _DEBUG
template <class U,class T> void Max(U &x, T y){if(x<y)x=y;}
template <class U,class T> void Min(U &x, T y){if(x>y)x=y;}
template <class T> void add(int &a,T b){a=(a+b)%mod;}
//inline int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
inline ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}

int pow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=1LL*ans*a%mod;
        a=1LL*a*a%mod;b>>=1;
    }
    return ans;
}

int pow(int a,int b,int c){
    int ans=1;
    while(b){
        if(b&1)ans=1LL*ans*a%c;
        a=1LL*a*a%c;b>>=1;
    }
    return ans;
}


int a[N],f[N],s[N];
int main(){
    //srand(time(NULL)+clock());
    int ca=0,T,k,i,j,m=0,n,K;
    scanf("%d",&n);
    rep(i,0,n)scanf("%d",&a[i]);
    f[1]=1;
    rep(i,2,n+1)f[i]=(mod-mod/i*(ll)f[mod%i]%mod)%mod;
    rep(i,1,n+1)s[i]=(s[i-1]+f[i])%mod;
    ll w=1;
    rep(i,2,n+1)w=w*i%mod;
    ll ans=0;
    rep(i,0,n){
        ll v=(s[i+1]+s[n-i]-f[1])%mod;
        ans+=v*a[i]%mod;
    }
    ans%=mod;
    if(ans<0)ans+=mod;
    ans=ans*w%mod;
    printf("%d\n",ans);
}
