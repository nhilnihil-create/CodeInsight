#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)


const long long INF = 1LL << 60;

int main()
{
   int a,b;
   cin >> a >> b;
   cout << ((a*b)%2 == 0 ? "Even": "Odd") << endl;
   return  0;
}
