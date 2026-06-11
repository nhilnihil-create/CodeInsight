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

vector<vector<int>> dp(100001, vector<int>(2, -1));

bool stones(vector<int>A, int k, int chance)
{
    int &ans = dp[k][chance];
    if(ans != -1) return ans;
    if(k<=0){ans = abs(1-chance); return ans;}
    else
    {
        int winner = chance;
        for(int i = 0; i<A.size(); i++)
        {
            if(k>=A[i])
            {
                int temp = stones(A, k-A[i], abs(chance-1));
                if(temp == winner) {ans = winner; return ans;}
            }
             
        }

        ans = abs(1-winner);
        return ans;
    }
    
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
        vector<int> A(n);
        for(int i = 0; i<n; i++) cin>>A[i];

        int res = stones(A, k, 0);

        if(res == 0) cout<<"First\n";
        else cout<<"Second\n";
        


    }
    
    return 0;
}

