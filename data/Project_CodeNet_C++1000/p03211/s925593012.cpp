#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
int main()
{
	string s,num;
	cin>>s;
	ll d,min_d=9999,n;
	REP(i,0,s.size()-3)
	{
		num=s.substr(i,3);
		n=stol(num);
		d=abs(753-n);
		min_d=min(d,min_d);
		num.erase(num.begin(),num.end());
	}
	cout<<min_d;
}