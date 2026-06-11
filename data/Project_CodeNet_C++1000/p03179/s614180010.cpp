
#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MP make_pair
#define PB push_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

#define int long long
#define trace(x) cerr << #x << ": " << x << " " << endl;


inline int add(int a, int b){a += b; if(a >= MOD)a -= MOD; return a;}
inline int sub(int a, int b){a -= b; if(a < 0)a += MOD; return a;}
inline int mul(int a, int b){return (int)((int) a * b %MOD);}


#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

signed main()
{
    IOS
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dp(n+1, 1);
    dp[0] = 0;
    REP(i, n-1)
    {
        // for(int x:dp)
        //     cout << x << " ";
        // cout << "\n";
        vector<int> ndp(n+1, 0);
        if(s[i] == '<')
        {
            FOR(k, 2, i+3, 1)
            {
                ndp[k] = sub(dp[k-1], dp[0]);

            }
        }
        else
        {
            FOR(k, 1, i+2, 1)
                ndp[k] = sub(dp[i+1], dp[k-1]);
            // ndp[i]+=dp[i];
        }
        // for(int x:ndp)
        //     cout << x << " ";
        // cout << "\n";
        FOR(k,1,i+3,1)
            ndp[k] = add(ndp[k], ndp[k-1]);
        dp = ndp;
        // for(int x:ndp)
        //     cout << x << " ";
        // cout  << "\n\n";
    }
    cout << dp[n] << "\n";
}