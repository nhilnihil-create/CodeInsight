#include<bits/stdc++.h>
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 
void c_p_c()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
 
int32_t main()
{
 // c_p_c();
  int n,k,pos = -1;
  cin >> n >> k;
  int a[n];
  for(int i=0;i<n;i++)
  {
    cin >> a[i];
  }
  if(k >= n)
  {
    cout<<1<<endl;
  }
  else
  {
    n--,k--;
    cout<<ceil(n/(k*1.0))<<endl;
  }
  
  return 0;
}