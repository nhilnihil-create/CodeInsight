#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ep emplace_back
#define st first
#define sc second

using namespace std;

const ll mod = 998244353;
const int e = 1e6 + 69;
const int base = 311;

// dung igt thay cho gt luc tinh giai thua
// 3
// cach tao hoan vi tu n so : n*(n+1)/2;

ll a[e];

int main()
{
   ll a, b, t;
   cin >> a >> b >> t;
   cout << t/a * b;
}
