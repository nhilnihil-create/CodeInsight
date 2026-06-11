#include<bits/stdc++.h>

using namespace std;


#define ss second
#define ff first
#define int long long
//#define double long double
#define pb push_back

const int N = 2e6 + 1, MOD = 1e9 + 7, mod = 998244353, INF = 3e17;

mt19937 Flash_new_51(51515);

using vi = vector <int>;
using vp = vector <pair <int, int>>;


signed main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);
   int n;
   cin >> n;
   vi a(n + 1);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   int kol = 0;
   a[n] = -1;
   for (int i = 1; i < n; i++) {
      if (a[i] == a[i - 1]) kol++, a[i] = -2;
   }
   cout << kol;

}
