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
  ll n, s=0, bs=0, m=0, c=0;
  cin >> n;
  vecll a(n), b(n);
  forll(i, 0, n){
	cin >> a[i];
	s += a[i];
  }
  forll(i, 0, n){
	cin >> b[i];
	a[i] = a[i] - b[i];
	if (a[i] < 0){
	  m -= a[i];
	  c++;
	}
	bs += b[i];
  }

  if (bs > s){
	cout << -1 << endl;
	return 0;
  }
  
  sort(a.begin(), a.end());
  
  forll(i, 0, n){
	if (m <= 0)
	  break;
	m -= a[a.size() - i - 1];
	c++;
  }
  cout << c << endl;
  
}
