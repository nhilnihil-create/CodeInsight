#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
const int inf = 0x3f3f3f3f3f3f3f3LL;
const int mod = (int)1e9 + 7;
using namespace std;
#if LOCAL
#include "../../tr.h"
#else
#define tr(...)
#define endl '\n'
#endif
template<class T, class T2> void smin(T& a, T2 val) {if (a > val) a = val;}template<class T, class T2> void smax(T& a, T2 val) {if (a < val) a = val;}
const int N = 5*(int)1e5 + 10;

int n;

int32_t main(){_
   
   cin>>n;
   vector<int> a(n);

   vector<int> dp(n, 0);
   for (int i = 0; i < n; ++i)
   {
      cin>>a[i];
      --a[i];
   }

   int ans = 0;
   for (int i = 0; i < n; ++i)
   {
      int idx = a[i];
      if (idx - 1 >= 0){
         smax(dp[idx], dp[idx-1] + 1);
      }
      else{
         dp[idx] = 1;
      }
      smax(ans, dp[idx]);
   }
      
   cout<<n - ans;

   return 0;
}