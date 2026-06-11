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
        int n, k;
        cin>>n>>k;
        int *h = new int[n];
        for(int i = 0; i<n; i++)cin>>h[i];

        int *dp = new int[n+1];
        for(int i = 0; i<=n; i++)dp[i] = INT_MAX;

        dp[n] = 0;
        for(int i = n-1; i>=1; i--)
        {
            for(int j = 1; j<=k; j++)
            {
                if(i+j>n)break;
                dp[i] = min(dp[i], dp[i+j] + abs(h[i-1] - h[i+j-1]));
            }

        }

        cout<<dp[1]<<"\n";


        delete [] h;
        
    }
    
    return 0;
}

