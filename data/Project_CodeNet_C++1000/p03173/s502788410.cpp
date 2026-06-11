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


vector<vector<int>> dp(400, vector<int>(400, -1));


int slimeCost(vector<int> &a, int i, int j, vector<int> &prefix_sum)
{
    int &val = dp[i][j];

    if(val != -1) return val;

    if(i >= j) val = 0;

    else
    {

        int ans = 1e16;

        for(int k = i; k<j; k++)
        {
            int temp = slimeCost(a, i, k, prefix_sum) + slimeCost(a, k+1, j, prefix_sum);
            if(i == 0) {temp += prefix_sum[k];}
            else temp += (prefix_sum[k] - prefix_sum[i-1]);

            temp += prefix_sum[j] - prefix_sum[k];

            ans = min(ans, temp);
        }

        val = ans;

    }

    

    return val; 
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
        int n;

        cin>>n;

        vector<int> a(n);

        for(int i = 0; i<n; i++) cin>>a[i];

        vector<int> prefix_sum(n);

        prefix_sum[0] = a[0];

        for(int i = 1; i<n; i++) prefix_sum[i] = prefix_sum[i-1] + a[i];

        int res = slimeCost(a, 0, n-1, prefix_sum);

        cout<<res<<"\n";

    }
    
    return 0;
}

    
