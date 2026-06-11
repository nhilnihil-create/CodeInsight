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
  ll r, g, b, n, c=0, t;
  cin >> r >> g >> b >> n;
  for(int i=0; i*r<=n; i++){
	for(int j=0; j*g<=n; j++){
	  t = n - i * r - j * g;
	  if(t % b == 0 && t >= 0)
		c++;
	}
  }
  cout << c << endl;
}

