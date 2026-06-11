#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <climits>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 



#define ll long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define mk make_pair
#define ff first
#define ss second
#define vi vector<int>
#define vii vector <pair <int , int>>
#define all(n) (n).begin(), (n).end()
#define INF 1000000000
#define pbds tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
void show(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
	   cout<<a[i]<<" ";
	}
}

ll minCost(ll n,ll h[])
{
	ll dp[n+1]={0};
    
    dp[1]=0;
    ll ans1,ans2;
    ans1=ans2=INT_MAX;
    for(int i=2;i<=n;i++)
    {
    	if(i>1)
    	ans1=dp[i-1]+abs(h[i]-h[i-1]);
    	if(i>2)
    	ans2=dp[i-2]+abs(h[i]-h[i-2]);
    	
    	dp[i]=min(ans1,ans2);
    }
	return dp[n];
}

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   ll n,h[100005];

   /*
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  */ 
  cin>>n;
  for(int i=1;i<=n;i++)
  {
  	cin>>h[i];
  }
  cout<<minCost(n,h);
  return 0;
}