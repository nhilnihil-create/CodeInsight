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
  ll d;
  string s, n;
  cin >> d >> n;
  forll(i, 0, 2 * d + n.size())
	s += "0";
  forll(i, 0, n.size())
	s[i] = n[i];
  if (n == "100")
	s[2] = '1';
  cout << s << endl;
}
