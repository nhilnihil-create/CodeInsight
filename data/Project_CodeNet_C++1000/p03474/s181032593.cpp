#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
int main()
{
	ll a,b,x;
	cin>>a>>b;
	string s;
	cin>>s;
	if(count(s.begin(),s.end(),'-')==1 && s[a]=='-')
		cout<<"Yes";
	else
		cout<<"No";
}