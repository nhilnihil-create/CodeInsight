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


void add_self(int &a, int b)
{
    a += b;
    if(a >= mod) a -= mod;
}


void sub_self(int &a, int b)
{
    a -= b;
    if(a < 0) a += mod;
}







int countWays(vector<int> a, int n, int k)
{

    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

    for(int i = 0; i<=n; i++) dp[i][0] = 1;

    for(int i = 1; i<=n; i++)
    {
        vector<int> prefix(k+1);

        prefix[0] = dp[i-1][0];

        for(int in = 1; in<=k; in++) 
            prefix[in] = ((prefix[in-1]%mod) + (dp[i-1][in]%mod))%mod;

        for(int j = 1; j<=k; j++)
        {
            
            int index = j - min(a[i-1], j);
            if(index == 0) add_self(dp[i][j], prefix[j]);
            else
            {
                dp[i][j] += (prefix[j] + mod - prefix[index-1])%mod;
            }
        }
    }

    return dp[n][k];

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
        int n, k;
        cin>>n>>k;

        vector<int> a(n);

        for(int i = 0; i<n; i++)cin>>a[i];


        cout<<countWays(a, n, k)<<"\n";


    }
    
    return 0;
}

