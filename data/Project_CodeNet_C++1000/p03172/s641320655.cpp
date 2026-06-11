#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


using namespace std;

#define int         long long
#define ld          double
#define vi          vector <int>
#define vp          vector <pair<int,int>>
#define vvi         vector <vector <int>>
#define pb          push_back
#define mp          make_pair
#define pi          pair<int,int>
#define all(a)      a.begin(),a.end()
#define sz(a)       a.size()
#define sl(a)       a.length()
#define rev(a)      sort(all(a),greater<int>())
#define ff          first
#define ss          second
#define minel(a)	*min_element(all(a))
#define maxel(a)	*max_element(all(a))
#define Mod         1000000007
#define deb(x)      cout << x << endl;
#define o(x)        for(auto a:x)cout << a <<" ";cout << endl;
#define o2(x,n,m)   for(int i =0;i<n;i++){for(int j=0;j<m;j++)cout << x[i][j] << " ";cout << endl; } 
#define i(x,n)      for(int i=0;i<n;i++)cin >> x[i];
#define i2(x,n,m)   for(int i =0;i<n;i++){for(int j=0;j<m;j++)cin >> x[i][j]; }
int inf = 1e18;




signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;

    
    vi a(n+1);
    for(int i=1;i<n+1;i++)cin >> a[i];

    int dp[n+1][k+1];


    for(int j=0;j<k+1;j++)dp[0][j]= 0;
    for(int i=0;i<n+1;i++)dp[i][0] = 1;

    vi pref(k+1,1);


    for(int i=1;i<n+1;i++)
    {
        for(int j =1;j<k+1;j++)
        {
            int x = max(j-a[i],(long long)0);
            if(x == 0)
            {
                dp[i][j] = pref[j];
            }
            else
            {
                dp[i][j] = (pref[j] - pref[x-1] + Mod)%Mod;
            }
        }
        pref.clear();
        pref.resize(k+1,0);
        pref[0] = dp[i][0];
        for(int j=1;j<k+1;j++)
        {
            pref[j] = (pref[j-1] + dp[i][j])%Mod;
        }
    }

    //o2(dp,n+1,k+1);

    deb(dp[n][k]);




    
}

