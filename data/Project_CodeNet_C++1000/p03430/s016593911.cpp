#include<bits/stdc++.h>
#include <ext/numeric>
using namespace std;
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)
#define pris() printf("\n")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false)
#define db(x) cerr << #x << " == " << x << endl
#define power(a,x) __gnu_cxx::power(a, x)
#define eps 1e-5
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9 + 7;
string s;
int t;
int dp[310][310][310];
int main()
{
    cin>>s>>t;
    int n=s.size();
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(i+1==j)
                dp[i][j][0]=1+(s[i]==s[j]);
            for(int k=0;k<=t;k++)
            {
                if(i==j)
                {
                    dp[i][j][k]=1;
                    continue;
                }
                if(i+1==j)
                {
                    if(k>0)
                        dp[i][j][k]=2;
                    continue;
                }
                int mx=0;
                mx=max(mx,dp[i+1][j][k]);
                mx=max(mx,dp[i][j-1][k]);
                if(k>0)
                    mx=max(mx,dp[i][j][k-1]);
                if(s[i]==s[j])
                    mx=max(mx,2+dp[i+1][j-1][k]);
                if(k>0)
                    mx=max(mx,2+dp[i+1][j-1][k-1]);
                dp[i][j][k]=mx;
            }
        }
    }
    cout<<dp[0][n-1][t]<<endl;
    return 0;
}

