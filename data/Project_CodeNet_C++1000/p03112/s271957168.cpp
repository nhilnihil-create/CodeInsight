#include<bits/stdc++.h>
//#include <ext/pb_ds/detail/standard_policies.hpp>

const double pi=acos(-1.0);
//memset ( a , 0 , n * sizeof(ll) ) ;
using namespace std;
//using namespace __gnu_pbds;
#define   endl    '\n'
#define   sl(n)     scanf("%lld",&n)
#define   mp      make_pair
#define   pb      push_back
#define   ppb     pop_back
#define   fi      first
#define   se      second
#define   ll      long long
#define   ull     unsigned long long
#define   ld      long double
#define   pii     pair<int, int>
#define   f(i,a,b)  for(ll i = (ll)(a); i < (ll)(b); i++)
#define   rf(i,a,b)   for(ll i = (ll)(a); i > (ll)(b); i--)
#define   ms(a,b)   memset((a),(b),sizeof(a))
#define   abs(x)    ((x<0)?(-(x)):(x))
#define   MAX     1000005
#define   inf     LLONG_MAX
#define   ninf    LLONG_MIN
#define   MIN     INT_MIN
#define   yeet    return 0;
#define tihs if(fopen("input.txt","r"))freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);

#define fast_io ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// Use cout.flush() for interactive problems.
// Use this for increased stack size: g++ -o a.exe -Wl,--stack=256000000 -O2 source.cpp
inline long long  MAX2(long long  a, long long  b){return (a)>(b)?(a):(b);}
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN2(long long  a, long long  b){return (a)<(b)?(a):(b);}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}

//typedef
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


int mod = 1e9 +7 ;
int64_t extGcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {if (!a) {x = 0;y = 1;return b;}int64_t x1, y1;int64_t d = extGcd(b % a, a, x1, y1);x = y1 - (b / a) * x1;y = x1;return d;}
inline ll addmod(ll a,ll b){a=a%mod+b%mod;if(a>mod)a%=mod;return a;}
inline ll submod(ll a,ll b){a=a%mod-b%mod;if(a<0)a+=mod;return a;}
inline ll mulmod(ll a,ll b){return (a%mod * b%mod)%mod;}

int dx[]={1,1,0,-1,-1,-1, 0, 1};
int dy[]={0,1,1, 1, 0,-1,-1,-1};
inline ll exp(ll a,ll b){if(a==0)return 0ll;ll r=1LL;while(b>0){if(b&1){r=r*(a%mod);r=(r+mod)%mod;}b/=2;a=(a%mod)*(a%mod);a=(a+mod)%mod;}return (r+mod)%mod;}
ll gcd(ll a,ll b){if(b==0)return a;if(a==0)return b;return gcd(b,a%b);}
uint32 setbits(ll n){uint32 count=0;while (n){n&=(n-1);count++;}return count; }

// ll f[MAX];
// ll iv[MAX];
// ll C(ll n,ll r){
//   if(n<r)return 0;
//   ll ans=(f[n]%mod * iv[r]%mod)%mod;
//   ans=(ans%mod * iv[n-r]%mod)%mod;
//   return ans%mod;
// }
// void init(){
//   f[0]=1;
//      iv[0]=1;
//      f(i,1,MAX)f[i]=(i*f[i-1])%mod;
//      iv[MAX-1]=exp(f[MAX-1],mod-2);

//      for(int i=MAX-2;i>=0;--i)iv[i]=(iv[i+1]*(i+1))%mod;

// }

////****************************************************************************************************************************************************************************************************************////


int main(){
     tihs;
     int n,m,q;
     cin>>n>>m>>q;
     ll a[n];
     ll b[m];
     f(i,0,n)cin>>a[i];
     f(i,0,m)cin>>b[i];
     ll ans= inf;
    while(q--){
           ll target;
           cin>>target;
           ans=inf;
           // look only left;
           
           ll len1,len2;
           int idx1=upper_bound(a,a+n,target)-a;
           if(idx1==0)len1=inf;
           else{if(idx1>0)idx1--;
             len1 =target-a[idx1];}
           int idx2= upper_bound(b,b+m,target)-b;
           if(idx2==0)len2=inf;
          else{ if(idx2>0)idx2--;
              len2=target-b[idx2];
              }
           ans=MIN2(ans,MAX2(len1,len2));
          
           //look only right;
            idx1=lower_bound(a,a+n,target)-a;
            if(idx1>=n)len1=inf;
            else len1= a[idx1]-target;
            idx2=lower_bound(b,b+m,target)-b;
            if(idx2>=m)len2=inf;
            else len2=b[idx2]-target;
            ans=MIN2(ans,MAX2(len1,len2));
         
            // look both side
            // 1) look left for shrine
              idx1=upper_bound(a,a+n,target)-a;
           if(idx1==0)len1=inf;
           else{if(idx1>0)idx1--;
             len1 =target-a[idx1];}
           //2)look right for shrine;
           idx1=lower_bound(a,a+n,target)-a;
            ll len11;
            if(idx1>=n)len11=inf;
            else len11= a[idx1]-target;
            len1=MIN2(len1,len11);

            //1)look left for temple;
            idx2= upper_bound(b,b+m,target)-b;
         
           if(idx2==0)len2=inf;
          else{ if(idx2>0)idx2--;
              len2=target-b[idx2];
              }
           idx2=lower_bound(b,b+m,target)-b;
            ll len22;
            if(idx2>=m)len22=inf;
            else len22=b[idx2]-target;
            
            len2=MIN2(len2,len22);
          
            ans=MIN2(ans, MIN2(len1,len2)*2  +MAX2(len1,len2));
            cout<<ans<<endl;



            


    }



      }
