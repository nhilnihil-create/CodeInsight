#include <bits/stdc++.h>
#define eps 1e-3
#define pi acos(-1.0)
#define inf 0x3f
#define INF 0x3f3f3f3f
#define pb push_back
#define debug1 cout<<"&&";
#define debug2 cout<<"**";
#define ms(a, x) memset(a, x, sizeof(a))
#define for0(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, int> pli;
typedef pair<long long, long long> pll;
const int mod = 1e9 + 7;
const int N = 1e3+10;
const int M = 2e4+10;
/*=================================================================================*/

struct node {
   int w, v, s;
}a[N];
ll n, dp[M], ans;

bool cmp(node a, node b) {
   return a.w+a.s < b.w+b.s;
}

int main() {
   cin>>n;
   for1(i, n) scanf("%d %d %d", &a[i].w, &a[i].s, &a[i].v);
   sort(a+1, a+1+n, cmp);

   for1(i, n) for(int j = M-10; j >= a[i].w; --j) {
      if(a[i].s + a[i].w >= j) dp[j] = max(dp[j], dp[j-a[i].w] + a[i].v);
   }

   for1(i, M) ans = max(ans, dp[i]);
   cout<<ans<<endl;
}