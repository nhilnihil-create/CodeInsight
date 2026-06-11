#include "bits/stdc++.h"
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define mFOR(i, a, b) for (int i = a; i > b; i--)
#define MP make_pair
#define PB push_back
#define ALL(v) v.begin(), v.end()
#define N 100007
#define INF 1000000007
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll fceil(ll a, ll b) { return (a % b == 0 ? a / b : a / b + 1); }
int main()
{
   int n;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++)
      cin >> a[i];
   sort(a.begin(), a.end());
   cout << a[n - 1] - a[0] << endl;
   return 0;
}
