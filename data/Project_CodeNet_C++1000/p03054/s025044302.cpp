#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
#define mod 1000000007
#define mod2 998244353 
#define PI 3.14159265
#define ll long long
#define ld long double
#define pi pair<ll,ll>
#define pb push_back
#define vi vector<ll>
#define sz size()
#define setbits(x)  __builtin_popcount(x)
#define fi first
#define se second
#define lz length()
#define all(x) (x).begin(),(x).end()
#define scf(x) scanf("%lld",&x)
#define rep(i,n) for(ll i=0;i<n;i++)
const int INF = (int)1e9;
const ll IINF=1LL<<62;
const int maxn=10000005;

//int divr[maxn];
/**/
/*void divisor()
{for(int i=2;i<sqrt(maxn);i++)
     {
          if(!divr[i])
          {
               for(int j=i*i;j<maxn;j+=i)if(!divr[j])divr[j]=i;     
          }
     }
     for(int i=1;i<maxn;i++)if(!divr[i])divr[i]=i;
}*/
 
/*const int N=1000005;
ll n;
struct line {
    long long m, c;
    long long eval(long long x) { return m * x + c; }
    long double intersectX(line l) { return (long double) (c - l.c) / (l.m - m); }
};
vector<pair<pi,ll>> rect;
deque<line> dq;
*/
/*int find(int a){
     if(a==par[a])return a;
     return par[a]=find(par[a]);
}
void unite(int a,int b){
     a=find(a),b=find(b);
     if(a==b)return ;
     par[b]=a;
}
ll modexpo(ll a,ll b)
{
     int ans=1LL;
     while(b>0)
     {
          if(b&1)ans=(ans*a)%mod;
          a=(a*a)%mod;
          b>>=1;
     }
     return ans;
}
*/




string s,t;
int len;

bool calc(int n,int st,char op1,char op2){
     int p=st;
     for(int i=0;i<len;i++){
          if(s[i]==op2){p++;if(p>n)return false;}
          if(t[i]==op1){p=max(p-1,1);}
     }
     p=st;
     for(int i=0;i<len;i++){
          if(s[i]==op1){
               p--;if(p<1){return false;}
          }
          if(t[i]==op2){p=min(p+1,n);}
     }
     return true;
}





int main(){
     int h,w,n;
     cin>>h>>w>>n;
     int sx,sy;
     cin>>sx>>sy;
     cin>>s>>t;
     len=s.length();
     bool res=calc(w,sy,'L','R')&&calc(h,sx,'U','D');
     if(res)cout<<"YES";
     else cout<<"NO";


}

















































