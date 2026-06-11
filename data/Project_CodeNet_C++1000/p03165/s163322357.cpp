#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define UB upper_bound
#define LB lower_bound
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define be(a) (a).begin(),(a).end()
#define deb(x) cout<< #x <<" "<<endl;
#define deb2(x, y) cout<< #x <<" "<< x <<endl<< #y <<" "<<y<<endl
#define fo(i, n) for(long long i=0; i<n; i++)
#define Fo(i, n, k) for(long long i=k; i<n; i++)
#define mod 1000000007
#define int long long

typedef long long ll;

void fileIO()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
 
typedef vector<pair<int, int>> vll;
typedef unordered_map<int, int> ump;



bool sortbysecdesc(const pair<int, int> &a, 
                    const pair<int, int> &b) 
{ 
    return a.second>b.second;
}



int32_t main()
{
    IOS;
    fileIO();
    int T;
    T = 1;
    //cin>>T;

    while(T--)
    {
        string s, t;
        cin>>s>>t;

        int m = s.size();
        int n = t.size();
        int dp[m+1][n+1];
        for(int i = 0; i<=m; i++) dp[i][0] = 0;
        for(int j = 0; j<=n; j++) dp[0][j] = 0;

        for(int i = 1; i<=m; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                if(s[i-1] == t[j-1])dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        string ans = "";
        int i = m, j = n;
        while(i>0 && j>0)
        {
            if(s[i-1] == t[j-1])
            {
                ans += s[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>=dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }

        reverse(ans.begin(), ans.end());
        cout<<ans;
    }
    
    return 0;
}

