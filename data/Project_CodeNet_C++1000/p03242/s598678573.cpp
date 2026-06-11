#ifdef __unix__
#include <bits/stdc++.h>
#else
#include <iostream>
#include <algorithm>
#include <math.h>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <bitset>
#endif

#define fastIO ios_base::sync_with_stdio(0), cin.tie(NULL)
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
#define mkp make_pair
/*#define NUMTOSTR(x)  (unsigned char)((x) + 48);*/
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long  ull;
using namespace std;


int main(){
	fastIO;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{

		if (s[i] == '9') s[i] = '1';
		else
		if (s[i] == '1') s[i] = '9';
	}
	cout << s;
	return 0;
}
