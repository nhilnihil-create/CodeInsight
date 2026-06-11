#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;
const ll N = (1 << 16);
ll dp[N];
ll p[N];

void func(ll pos , vector<ll>v , ll mask , ll group , ll points)
{
    if(pos == (ll)v.size())
    {
        dp[mask] = max(dp[mask] , points+p[group]);
        return;
    }

    func(pos+1 , v , mask , group , points);
    func(pos+1 , v , (mask^(1 << v[pos])) , (group^(1 << v[pos])) , points);
}


int main() {
   ll n;
   cin >> n;
   ll g[n][n];
   for(ll i = 0 ; i < n ; i++)
   {
       for(ll j = 0 ; j < n ; j++)
       cin >> g[i][j];
   }

   for(ll mask =0 ; mask < (1 << n) ; mask++)
   {
       for(ll i =0 ; i < n ; i++)
       {
           if((mask&(1 << i)))
           {
               for(ll j = i+1 ; j < n ; j++)
               {
                    if((mask&(1 << j)))
                    {
                        p[mask] += g[i][j];
                    }    
               }
           }
       }
   }



   for(ll mask = 0 ; mask < (1 << n) ; mask++)
   {
       vector<ll>v;
       for(ll i = 0 ; i < n ; i++)
       {
           if(!(mask & (1 << i)))
            v.push_back(i);
       }
       func(0 , v , mask , 0 , dp[mask]);
   }

   cout << dp[(1 << n)-1];  
}
