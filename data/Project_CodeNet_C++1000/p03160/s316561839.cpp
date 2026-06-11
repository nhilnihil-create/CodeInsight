#include <algorithm>
#include <iostream>
#include <cstring>
#include <complex>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <vector>  
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>    // PBDS
#include <ext/pb_ds/tree_policy.hpp>      // PBDS

using namespace std;
using namespace __gnu_pbds;                 // PBDS

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS_INT;               // PBDS for int
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> PBDS_LL;    // PBDS for long long

/* typedef ends */

/* macro starts */

#define PI acos(-1)
#define EPS 1e-9
#define INF ll(1e9 + 7)
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sinD(degree) sin((degree * PI) / 180.0)
#define cosD(degree) cos((degree * PI) / 180.0)
#define tanD(degree) tan((degree * PI) / 180.0)
#define cotD(degree) (1.0 / tanD(degree))
#define secD(degree) (1.0 / cosD(degree))
#define cosecD(degree) (1.0 / sinD(degree))
#define asinD(value) (asin(value) * 180.0) / PI
#define acosD(value) (acos(value) * 180.0) / PI
#define atanD(value) (atan(value) * 180.0) / PI
#define forn(i,n) for(int i=0;i<n;i++)
#define value_at_index(x) find_by_order(x)
#define index_of(x) order_of_key(x)
#define pb push_back
#define set0(add) memset(add,0,sizeof(add))
#define max(a,b) a>b ? a : b
#define forr(i,a,b) for(int i=a;i<b;i++)

/* macro ends */

/* function starts */

/// calculates n-th (0-based) Gray Code
template<typename dataType>
dataType nthGrayCode(dataType n)
{
    return (n ^ (n >> 1));
}

/// generates all possible subsets for the given set
//template<typename dataType>
// void generateAllSubset(vector<dataType> &data)
// {
//     int i, j, n;
//     n = data.size();

//     for (i = 0; i < (1 << n); i++) {
//         for (j = 0; j < n; j++) {
//             if (i & (1 << j)) {
//                 cout << data[j] << " ";
//             }
//         }
//         cout << "\n";
//     }
// }


void swap(ll *a, ll *b){
	ll *temp=a;
	*a=*b;
	*b=*temp;
}
int n;
int dp[100005];
int a[100005];

int solve(int n){
for(int i=1;i<=n;i++){
  dp[i+2]=min(dp[i]+abs(a[i+2]-a[i]),dp[i+1]+abs(a[i+1]-a[i+2]));
}
return dp[n];
}
  
void solve(){
cin >> n;
forr(i,1,n+1)cin >> a[i];
set0(dp);
dp[2]=abs(a[2]-a[1]);
int ans=solve(n);
cout << ans << "\n";

}






int main()
{
  #ifndef ONLINE_JUDGE
       freopen("in.txt", "r", stdin);
       freopen("out.txt", "w", stdout);
  #endif
  fastIO;
    int t=1;
    //cin >> t;
    while(t--){
     solve();
    }
    return 0;
    }