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
    int T;
    T = 1;
    //cin>>T;

    while(T--)
    {
        int n;
        cin>>n;
        int *a = new int[n];
        int *b = new int[n];
        int *c = new int[n];

        for(int i = 0; i<n; i++)cin>>a[i]>>b[i]>>c[i];

        int ans = 0;
        int dp[n][3];

        dp[0][0] = a[0]; dp[0][1] = b[0]; dp[0][2] = c[0];

        for(int i = 1; i<n; i++)
        {
            dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = c[i] + max(dp[i-1][0], dp[i-1][1]);
        }

        cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));


        delete [] a;
        delete [] b;
        delete [] c;
        
    }
    
    return 0;
}

