//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long ll;
int main()
{
	//fast;
	ll i = 0, fl = 1;
	string a, b;
	char ch;
	cin >> a >> b;
	for(i=0;i<105;i++)
	{
		if (a == b)
		{
			fl = 0;
			cout << "Yes\n";
			break;
		}
	   ch=a[0];
		a.erase(a.begin());
		a+=ch;
	}
	if (fl)
		cout << "No\n";
}