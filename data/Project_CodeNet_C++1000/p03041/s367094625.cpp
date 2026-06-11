
#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll

int32_t main()
{
	string s;
	int n,k;
	cin>>n>>k;
	cin>>s;
	s[k-1]=tolower(s[k-1]);
	cout<<s;
	
}