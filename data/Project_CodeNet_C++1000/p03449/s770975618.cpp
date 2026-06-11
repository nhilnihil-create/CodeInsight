#pragma warning(disable : 4996)
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<stdio.h>
#include<map>
#include<set>
#include<limits.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
	int n, mx = 0;
	cin >> n;
	vector<int> v1(n), v2(n);
	for (int i = 0; i < n; i++)
		cin >> v1[i];
	for (int i = 0; i < n; i++)
		cin >> v2[i];
	for (int i = 1; i < n; i++)
		v1[i] += v1[i - 1];
	for (int i = n - 2; i >= 0; i--)
		v2[i] += v2[i + 1];
	for (int i = 0; i < n; i++)
		mx = max<int>(mx, v1[i] + v2[i]);
	cout << mx;
}