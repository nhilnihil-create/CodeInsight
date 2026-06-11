// coded by zeffy
#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zeroupper") //Enable AVX
#pragma GCC target("avx","popcnt")  //Enable AVX
#include <x86intrin.h> //SSE Extensions
#include <bits/stdc++.h> 
using namespace std;
#define eb emplace_back
#define mp make_pair
#define hello cout<<"hello"<<"\n"
#define forr(i,a,b) for(int i=a;i<b;i++)
#define it(s)	for(auto itr:s)
#define dvg(s) 	for(auto itr:s)	cout<<itr<<" ";cout<<endl;
#define dbg(s)	cout<<#s<<"= "<<s<<endl;
typedef long long int lli;
typedef unsigned long long int ulli;
const lli INF=(lli)1e17+5;
const ulli MOD=1e8+7;

int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(10);
    
    int n;cin>>n;
    lli a,b,c;
    cin>>a>>b>>c;
    lli dp[3];memset(dp,0,sizeof(dp));
    dp[0]=a;dp[1]=b;dp[2]=c;

    forr(i,1,n)
    {
       cin>>a>>b>>c;
       lli ndp[3];memset(ndp,0,sizeof(ndp));
       ndp[0]=a+max(dp[1],dp[2]);
       ndp[1]=b+max(dp[0],dp[2]);
       ndp[2]=c+max(dp[1],dp[0]);

       dp[0]=ndp[0];
       dp[1]=ndp[1];
       dp[2]=ndp[2];
    }

    cout<<max(dp[0],max(dp[1],dp[2]))<<"\n";
   return 0;
}