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
        int h, w;
        cin>>h>>w;
        vector<string>grid;

        for(int i = 0; i<h; i++)
        {
            string input;
            cin>>input;
            grid.push_back(input);
        }

        vector<vector<int>> dp;
        for(int i = 0; i<h; i++)
        {
            vector<int> temp;
            for(int j = 0; j<w; j++)
            {
                temp.push_back(0);
            }

            dp.push_back(temp);
        }

        
        dp[0][0] = 0;
        for(int i = 1; i<h; i++)
        {
            if(grid[i][0] != '#')dp[i][0] = 1;
            else break;
        }

        for(int i = 1; i<w; i++)
        {
            if(grid[0][i] != '#')dp[0][i] = 1;
            else break;
        }

        for(int i = 1; i<h; i++)
        {
            for(int j = 1; j<w; j++)
            {
                if(grid[i][j] != '#')
                {
                    dp[i][j] = ((dp[i][j-1]%mod) + (dp[i-1][j]%mod))%mod;
                }
            }
        }


        cout<<dp[h-1][w-1];




    }
    
    return 0;
}

