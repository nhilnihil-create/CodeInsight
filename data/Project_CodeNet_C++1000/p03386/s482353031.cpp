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
  ll a, b, k;
  cin >> a >> b >> k;
  if (b - a + 1 >= 2 * k){
	forll(i, 0, k)
	  cout << a + i << endl;
	forllde(i, k)
	  cout << b - i + 1 << endl;
  }else{
	forll(i, a, b + 1)
	  cout << i << endl;
  }
}
