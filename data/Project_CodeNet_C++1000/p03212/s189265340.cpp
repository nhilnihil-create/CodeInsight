#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
ll n;
ll digit;
int getDigit(ll i)
{
	int dig = 0;
	while (i != 0) {
		i /= ll(10);
		dig++;
	}
	return dig;
}
void rec(vector<ll> &v, ll i)
{
	if (digit < getDigit(i)) return;
	if (v.size() == 0) {
		v.push_back(3);
		v.push_back(5);
		v.push_back(7);
		rec(v, 3);
		rec(v, 5);
		rec(v, 7);
	}
	else {
		v.push_back(i * 10 + 3); rec(v, i * 10 + 3);
		v.push_back(i * 10 + 5); rec(v, i * 10 + 5);
		v.push_back(i * 10 + 7); rec(v, i * 10 + 7);
	}
}
bool judge(ll i)
{
	string s = to_string(i);
	bool three, five, seven;
	three = five = seven = false;
	rep(i, s.size()) {
		if (s[i] == '3') three = true;
		if (s[i] == '5') five = true;
		if (s[i] == '7') seven = true;
	}
	if (three && five && seven) return true;
	return false;
}
int main()
{
	// ABC114-C, 1061, UNSOLVED, 
	cin >> n;
	digit = getDigit(n);
	vector<ll> v;
	rec(v, 0);
	vector<ll> v2;
	rep(i, v.size()) {
		if (judge(v[i])) v2.push_back(v[i]);
	}
	if (v2.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	sort(v2.begin(), v2.end());
	//rep(i, v2.size()) cout << v2[i] << endl;
	int low, high, mid;
	low = 0;
	if (n < v2[low]) {
		cout << 0 << endl;
		return 0;
	}
	high = v2.size() - 1;
	mid = (high - low) / 2;
	while (1 < high - low) {
 		if (v2[mid] <= n) low = mid;
		else high = mid;
		mid = (high + low) / 2;
	}
	cout << high << endl;
	

	return 0;
}