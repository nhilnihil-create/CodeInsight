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
  ll n, m, x;
  cin >> n;
  map<ll, ll> d;
  forll(i, 0, n){
	cin >> x;
	d[x]++;
  }

  cin >> m;
  forll(i, 0, m){
	cin >> x;
	d[x]--;
	if (d[x] < 0){
	  cout << "NO" << endl;
	  return 0;
	}
  }
  cout << "YES" << endl;
}
