/* In the name of ALLAH */
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

// MAXIMUM and MINIMUM elements
#define mx_ari(a)   *max_element(a , a+sizeof(a)/4)
#define mn_ari(a)   *min_element(a , a+sizeof(a)/4)
#define mx_arl(a)   *max_element(a , a+sizeof(a)/8)
#define mn_arl(a)   *min_element(a , a+sizeof(a)/8)
#define mx_vec(v)   *max_element(v.begin() , v.end())
#define mn_vec(v)   *min_element(v.begin() , v.end())
// COUNT the occurence of an element
#define cnt_ari(a,b)   count(a , a+sizeof(a)/4 , b)
#define cnt_arl(a,b)   count(a , a+sizeof(a)/8 , b)
#define cnt_vec(v,b)   count(v.begin() , v.end() , b)
// INPUTs
#define sci(a)        scanf("%d",&a)
#define scii(a,b)     scanf("%d %d",&a,&b)
#define sciii(a,b,c)  scanf("%d %d %d",&a,&b,&c)
#define scl(a)        scanf("%lld",&a)
#define scll(a,b)     scanf("%lld %lld",&a,&b)
#define sclll(a,b,c)  scanf("%lld %lld %lld",&a,&b,&c)
#define scf(a)        scanf("%f",&a)
#define scff(a,b)     scanf("%f %f",&a,&b)
#define scfff(a,b,c)  scanf("%f %f %f",&a,&b,&c)
#define scd(a)        scanf("%ld",&a)
#define scdd(a,b)     scanf("%lf %lf",&a,&b)
#define scddd(a,b,c)  scanf("%lf %lf %lf",&a,&b,&c)
// OUTPUTs
#define pri(a)        printf("%d ",a)
#define prii(a,b)     printf("%d %d ",a,b)
#define priii(a,b,c)  printf("%d %d %d ",a,b,c)
#define prl(a)        printf("%lld ",a)
#define prll(a,b)     printf("%lld %lld ",a,b)
#define prlll(a,b,c)  printf("%lld %lld %lld ",a,b,c)
#define prd(a)        printf("%.4lf ",a)
#define prdd(a,b)     printf("%.4lf %.4lf ",a,b)
#define prddd(a,b,c)  printf("%.4lf %.4lf %.4lf ",a,b,c)
#define prf(a)        printf("%.4f ",a)
#define prff(a,b)     printf("%.4f %.4f ",a,b)
#define prfff(a,b,c)  printf("%.4f %.4f %.4f ",a,b,c)
// LOOPs
#define foi(i,n)      for(int i=0;i<n;i++)
#define fol(i,n)      for(long long int i=0;i<n;i++)
#define fod(i,n)      for(double i=0;i<n;i++)
#define fof(i,n)      for(float i=0;i<n;i++)
// NEWLINEs
#define nwl           << "\n"
#define nl            printf("\n");
// PAIRs and PUSHbacks
#define mp            make_pair
#define pb            emplace_back
// IMPORTANTs
#define ll          long long
#define ull         unsigned long long int
#define mod         1000000007
#define lcm(a,b)     (a*b) / __gcd(a,b)

using namespace std;






int main()
{
   ll n; cin >> n;
   ll dp[n][3];
   ll a[n][3];

   fol(i,n){
      fol(j,3){
         cin >> a[i][j];
      }
   }
   
   dp[0][0] = a[0][0];
   dp[0][1] = a[0][1];
   dp[0][2] = a[0][2];

   for(ll i=1;i<n;i++){
      dp[i][0] = a[i][0] + max(dp[i-1][1] , dp[i-1][2]);
      dp[i][1] = a[i][1] + max(dp[i-1][0] , dp[i-1][2]);
      dp[i][2] = a[i][2] + max(dp[i-1][1] , dp[i-1][0]);
   }

   cout << max(dp[n-1][0] , max(dp[n-1][1] , dp[n-1][2]));

   return 0;
}