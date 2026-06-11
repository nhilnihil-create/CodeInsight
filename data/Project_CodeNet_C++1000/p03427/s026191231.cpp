#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vecll vector<long long>
#define vecs vector<string>
#define vec2ll vector<vector<long long>>
#define vecbool vector<bool>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)

int main()
{
  ll v, c9=0;
  string n;
  cin >> n;
  forll(i, 0, n.size()){
	if (n[n.size() - 1 - i] == '9')
	  c9 += 1;
	else
	  break;
  }
  ll r = n.size() - c9;
  if (r > 1)
	cout << 9 * (r - 1) + (ll)(n[0] - '0') - 1 + 9 * c9 << endl;
  else if (r == 1)
    cout << n[0] - '0' + 9 * c9 << endl;
  else
	cout << 9 * c9 << endl;
}