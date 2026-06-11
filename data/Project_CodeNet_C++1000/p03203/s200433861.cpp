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
#define ull unsigned long long
#define DBG(x) cerr<<(#x)<<"="<<x<<"\n";
#define N 200010
#define _DEBUG
template <class U,class T> void Max(U &x, T y){if(x<y)x=y;}
template <class U,class T> void Min(U &x, T y){if(x>y)x=y;}
template <class T> void add(int &a,T b){a=(a+b)%mod;}
inline int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
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

pii a[N];
bool cmp(pii a,pii b){
    if(a.y!=b.y)return a.y<b.y;
    return a.x<b.x;
}
int main(){
    //srand(time(NULL)+clock());
    int ca=0,T,k,i,j,m=0,n,K;
    double start=clock();
    int h,w;
    scanf("%d%d%d",&h,&w,&n);
    rep(i,0,n)scanf("%d%d",&a[i].x,&a[i].y);
    sort(a,a+n,cmp);
    int x=1,y=1,res=h,ans=0;k=0;
    while(x<=h){
        //cerr<<x<<" "<<y<<" "<<ans<<"\n";
        while(k<n&&a[k].y<y)k++;
        while(k<n&&a[k].y==y&&a[k].x<=x)k++;
        //if(k<n)cerr<<a[k].x<<" "<<a[k].y<<"\n";
        if((k<n&&a[k]==mp(x+1,y))||x==h){ans++;break;}
        ans++;x++;
        if(k<n&&a[k].y==y){
            Min(res,ans+a[k].x-x);
        }
        else Min(res,ans+h-x+1);
        while(k<n&&a[k].y==y)k++;
        while(k<n&&a[k].y==y+1&&a[k].x<x)k++;
        if(!(k<n&&a[k]==mp(x,y+1))&&y<w)y++;
    }
    Min(res,ans);
    printf("%d\n",res);
    cerr<<(1.*clock()-start)/CLOCKS_PER_SEC<<"\n";
}
