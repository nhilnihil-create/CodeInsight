#include<bits/stdc++.h>
using namespace std;
#define lc "\n"
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define c(a,n) for(int i = 0; i < n; i++) cin >> a[i];
#define ffor(n) for(int i = 0; i < n; i++)
#define float long double
typedef vector<int> vi;
typedef vector<float> vf;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<string,int> msi;
typedef map<int,int> mii;
typedef unordered_map<string,int> umsi;
 
 
int32_t main()
{
    fast_io;
    
       int n,k;
       cin>>n>>k;
       vi a(n);
       c(a,n);
       vi dp(k+1,0);
       dp[0]=0;
       if(k<a[0])
           cout<<"Second";
         
       else{

       for(int i=1;i<=k;i++)
       {
           for(int j=0;j<n;j++){
               if(i-a[j]>=0 ){
                   if(dp[i-a[j]]==0){dp[i]=1;break;}
               }
           }
       }
        if(!dp[k])cout<<"Second";
        else cout<<"First";
       }
    return 0;
}