#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#define mod 1000000009
#define ll long long
using namespace std;
int main() {
	int a, b, c;
	vector<int>v;
	cin >> a >> b >> c;
	v.push_back(a);v.push_back(b);v.push_back(c);
	sort(v.begin(), v.end());
	cout << (v[2] * 10 + v[1] + v[0]);
}