#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int main()
{
   int n;
   cin >> n;
   vector<int> a(n);
   rep(i,n)cin >> a[i];
   ll odd = 0;
   rep(i,n)odd+=a[i]%2;
   ll even = n-odd;
   ll ff = (1LL<<even);
   ll ans = 1;
   rep(i,n)
   {
      ans*=3;
   }
   ans -= ff;
   cout<<ans<<endl;
   
   return 0;
}