#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)


int main()
{
  ll n, x=1e9 + 7, c=1;
  string s;
  cin >> n >> s;
  vecll a(26, 0);
  forll(i, 0, n)
	a[s[i] - 'a']++;
  forll(i, 0, 26)
	c = c * (a[i] + 1) % x;
  cout << c - 1 << endl;
}
