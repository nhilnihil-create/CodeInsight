//#pragma warning(disable : 4996)
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<stdio.h>
#include<map>
#include<set>
#include<limits.h>
#include<list>
#include <cassert>
#include<sstream>
#include <bitset>
#include<unordered_map>
using namespace std;
using ll = long long int;
using uint = unsigned int;

bool eqlvv(const vector<int>& l, const vector<int>& r) {
	if (l.size() != r.size())
		return false;
	for (int i = 0; i < l.size(); ++i)
		if (l[i] != r[i])
			return false;
	return true;
}
int main() {
	vector<int> fs[2] = { vector<int>(257, -1), vector<int>(257, -1) };
	int cnt[2] = { 0 };
	string s[2];
	cin >> s[0] >> s[1];
	vector<int> Sparse[2] = { vector<int>(s[0].size()), vector<int>(s[0].size()) };
	for (int i = 0; i < s[0].size(); ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (fs[j][s[j][i]] == -1) {
				fs[j][s[j][i]] = cnt[j]++;
			}
			Sparse[j][i] = fs[j][s[j][i]];
		}
	}
	cout << (eqlvv(Sparse[0], Sparse[1]) ? "Yes" : "No");

	return 0;
} 
