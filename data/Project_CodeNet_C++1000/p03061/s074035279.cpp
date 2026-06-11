#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include <algorithm>
#include <bits/stdc++.h>
#define ll long long int
#define sc(a) scanf("%lld",&a)
const int mod=998244353;
using namespace std;
const int inf=1e9+7;
const int maxn=2e5+10;
 
ll n,m;
int sum,t,p,res;
int a[maxn],b[maxn],c[maxn];
ll x,y;
ll dp[110][110];
ll maxx=-1,num=-1;
char str[maxn],s[maxn],ss[maxn];
 
int gcd (int a,int b){
    while(b){
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}
 
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);//x
     
    b[1]=a[1];
    for(int i=2;i<=n;i++)
        b[i]=gcd(b[i-1],a[i]);//前缀gcd 
     
    c[n]=a[n];
    for(int i=n-1;i>=1;i--)//后缀gcd 
        c[i]=gcd(c[i+1],a[i]);
     
    for(int i=2;i<n;i++)
        sum=max(gcd(b[i-1],c[i+1]),sum);
     
    cout<<max(sum,max(c[2],b[n-1]))<<endl;
    return 0;
}
