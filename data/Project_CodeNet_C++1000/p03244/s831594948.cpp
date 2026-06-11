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
  ll n, x, y;
  cin >> n;
  vec2ll v(2, vecll(100000));
  vecll e0(2), e1(2), e2(2);
  forll(i, 0, n){
	cin >> x;
    x--;
	y = i & (ll)1;
	v[y][x]++;
	if(v[y][x] > e1[y]){
	  e1[y] = v[y][x];
	  e0[y] = x + 1;
	}else if(v[y][x] > e2[y]){
	  e2[y] = v[y][x];
	}
  }
  cout << n - (e0[0]!=e0[1]? e1[0]+e1[1]: max(e1[0]+e2[1], e2[0]+e1[1])) <<endl;
}
