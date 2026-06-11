#include <cstdio>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <utility>
#include <ctime>
#include <cassert>
#include <climits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii > vii;
typedef vector<pair<int, pair<int, int> > > viii;
typedef pair<ll,ll> pll;
typedef vector<string> vs;
typedef vector<vii> vvii;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MEM(a,b) memset(a,(b),sizeof(a))
#define tr(c,it) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define all(a) a.begin(),a.end()
#define loop(x,a,b) for(int (x) = (a);(x)<(b);(x)++)
#define rep(x,n)   for(int (x)=0;(x)<(n);(x)++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ain(a,n) int ((a)[(n)]); for(int i=0; i<(n); i++) cin>>((a)[i])  
#define md 1000000007
#define MAXN 200005

ll dp[5001][5001];

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    int array[n+1];
    array[0] = 0;
    rep(i,n)
      cin>>array[i+1];

    rep(i,n+1)
      rep(j,n+1)
        dp[i][j] = 1e18;

    dp[0][0] = 0;
    rep(i,n)
      rep(j,n+1)
      {
        if(array[i+1] > array[j])
          dp[i+1][i+1] = min(dp[i+1][i+1], dp[i][j]);
        dp[i+1][j] = min(dp[i+1][j], dp[i][j] + (array[i+1] > array[j]? a : b));
      }
    ll ans = 1e18;
    rep(i,n+1)
      ans = min(ans, dp[n][i]);
    cout<<ans;
    return 0;
}
