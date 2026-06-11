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

bool isok(int n) {
	unordered_multiset<char> ums;
	for (auto& i : to_string(n)) ums.insert(i);
	if (ums.count(n % 10 + '0') == ums.size()) return true;
	return false;
}

int main(){
	fastIO;
	int n;
	cin >> n;
	while (true)
	{
		if (isok(n)) {
			cout << n;
			return 0;
		}
		n++;
	}
	return 0;
}

