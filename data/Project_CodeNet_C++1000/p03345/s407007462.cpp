#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define vecbool vector<bool>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)

int main()
{
  ll a, b, c, k, x;
  cin >> a >> b >> c >> k;
  if (k % 2 == 0)
	x = a - b;
  else
	x = b - a;
  cout << x << endl;
}