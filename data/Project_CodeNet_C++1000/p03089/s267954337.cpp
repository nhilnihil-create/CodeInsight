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
  ll n, g;
  cin >> n;
  vecll b(n);
  vecll a(n);
  forll(i, 0, n)
	cin >> b[i];
  forll(i, 0, n){
	g = -1;
	forll(j, 0, b.size()){
	  if(b[j] == j+1)
		g = j;
	}
	if (g == -1 ){
	  cout << -1 << endl;
	  return 0;
	}
	a[n-i-1] = b[g];
	b.erase(b.begin() + g);
  }
  forll(i, 0, n)
	cout << a[i] << endl;
}

