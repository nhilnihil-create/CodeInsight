#define _GLIBCXX_DEBUG
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
  ll k, a, b;
  cin >> k >> a >> b;
  if (b - a > 2){
	k -= (a-1);
	cout << a + (b - a) * (k / 2) + k % 2 << endl;
  }
  else
	cout << 1 + k << endl;
}
