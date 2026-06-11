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
  ll n, even=0, a;
  cin >> n;
  forll(i, 0, n){
	cin >> a;
	if (a % 2 == 0)
	  even++;
  }
  cout << pow(3, n) - pow(2, even) << endl;
}