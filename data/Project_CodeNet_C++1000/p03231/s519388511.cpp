#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)


ll gcd(ll a,ll b){
  if(a<b)swap(a,b);
  if(a%b==0)return b;
  return gcd(a%b,b);
}

ll lcm(ll a,ll b){
  return a/gcd(a,b)*b;
}


int main()
{
  ll n, m, lcmnm;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  lcmnm = lcm(n, m);
  forll(i, 0, m){
	if (n * i % m == 0){
	  if (t[i] != s[i * n / m]){
		cout << -1 << endl;
		return 0;
	  }
	}
  }
  cout << lcmnm << endl;
}
