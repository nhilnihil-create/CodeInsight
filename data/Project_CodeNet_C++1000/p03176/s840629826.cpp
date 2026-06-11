#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long 
#define pb push_back
#define fo(i,N) for(int i = 0 ; i < N ; i++)
#define foo(i,x,N) for (int i = x; i < N ; i++)
#define fill(a,val) memset(a,val,sizeof(a))
#define fastio()  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define ff first
#define ss second
#define MAX 1234567
#define pii pair<int,int> 
#define pll pair<ll,ll> 
#define inf 1e14+1
#define all(a) a.begin(),a.end()
int n;
vector <int> h(200005);
vector <int> a(200005);
ll dp[200005];

ll solve()
{
   dp[1] = a[1];
   ll ans = a[1];

   map <ll,ll> mp;
   mp[h[1]] = a[1];

   foo(i,2,n+1)
   {
     dp[i] = a[i];
     auto it = mp.lower_bound(h[i]);
     if ( it != mp.begin())
     {
      it--;
      dp[i] += it->second;
     }
       mp[h[i]] = dp[i];
    it = mp.upper_bound(h[i]);
     while ( it != mp.end() && it->second <= dp[i])
   {
    auto temp = it;
    temp++;
    mp.erase(it);
    it = temp;
    }
      ans = max(ans,dp[i]);  
    }
   
   return ans;


}

int main()
{ 
  cin >> n;
  foo(i,1,n+1)
  cin >> h[i];
  foo(i,1,n+1)
  cin >> a[i];

  cout << solve() << endl;

}