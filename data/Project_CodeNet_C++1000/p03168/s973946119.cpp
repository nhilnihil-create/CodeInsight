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

double dp[3001][1502];

bool sortbysecdesc(const pair<int, int> &a, 
                    const pair<int, int> &b) 
{ 
    return a.second>b.second;
}

// double coins(double p[], double prod[], int n, int k)
// {
//     double ans;
//     if(n == 0 || k == 0)ans = 1.0;    
//     else if(n < k)ans =  0.0;
//     else if(n == k)ans = prod[n-1];
//     else
//     {
//         double one = 1.0;
//         ans =  (p[n-1]*coins(p, prod, n-1, k-1) + (one - p[n-1])*coins(p, prod, n-1, k));
//     }


//      return ans;

    
    
    

// }



int32_t main()
{
    IOS;
    fileIO();
    int T;
    T = 1;
    //cin>>T;

    while(T--)
    {
        int n;
        cin>>n;
        double *p = new double[n];
        for(int i = 0; i<n; i++)cin>>p[i];

        double *prod = new double[n];
        prod[0] = p[0];
        for(int i = 1; i<n; i++) prod[i] = p[i]*prod[i-1];

        int k = (n/2) + 1;

        double one = 1.0;


        cout<<std::fixed;


        for(int i = 0; i<=k; i++) dp[0][i] = 1.0;
        for(int i = 0; i<=n; i++) dp[i][0] = 1.0;

        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=k; j++)
            {
                if(i<j) dp[i][j] = 0;
                else if(i == j)dp[i][j] = prod[i-1];
                else
                {
                    dp[i][j] = p[i-1]*dp[i-1][j-1] + (one - p[i-1])*dp[i-1][j];
                }
            }
        }

        // double res = coins(p, prod, n, k);

        // cout<<res<<"\n";

        cout<<setprecision(10)<<dp[n][k]<<"\n";

    }
    
    return 0;
}

