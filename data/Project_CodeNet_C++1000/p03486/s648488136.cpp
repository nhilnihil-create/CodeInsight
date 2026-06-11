#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <bitset>
#include<unordered_map>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
#define endl '\n'
#define exit(s) return cout<<s,0;
#define sz(s) (int)(s.size())
#define all(s) s.begin(),s.end()
#define allr(s) s.rbegin(), s.rend()
#define watch(x) cout << (#x) << " = " << x << endl
#define DNT ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
	string s, t;
	cin >> s >> t;
	sort(all(s));
	sort(allr(t));
	if (s < t)
	{
		cout << "Yes" << endl;
	}
	else
		cout << "No" << endl;
	
		return 0;
}