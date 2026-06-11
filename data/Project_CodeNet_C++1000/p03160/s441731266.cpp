#include<bits/stdc++.h>
#define int long long int
#define endl "\n"
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define loop(i,n) for(int i=0;i<(n);i++)
#define fors(a,b,i) for(int i=(a);i<=(b);i++)
#define ford(a,b,i) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fastm_fast ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL)
using namespace std;
const int  mod = 1e9 + 7;
#define pb push_back
#define mp make_pair
#define S second
#define F first
const int MAX = 1e5;
void sujho()
{
   
   
   int n;
   cin >> n;
   
   vector<int> v(n+1);
   
   loop(i,n) cin >> v[i+1];
   
   vector<int> dp(n+1,INT_MAX);
   
   dp[0] = 0;
   
   dp[1] = 0;
   
   dp[2] = dp[1] + abs(v[2] - v[1]);
   
   for(int i = 3; i <= n; i++)
   {
      dp[i] = min(dp[i-1] +abs(v[i] - v[i-1]) , dp[i-2]+abs(v[i] - v[i-2]) );
   }
   cout<<dp[n]<<endl;
   
   
   
   
}
int32_t main()
 {
 fastm_fast;
//  int tt;
//  cin >> tt;
//  while(tt--)
  {
    sujho();
 }
 return 0;
 }