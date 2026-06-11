//#define __popcnt __builtin_popcount
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define clr(v,val) memset(v , val , sizeof v)
#define EPS 1e-6
#define OO 1e9
#define PI acos(-1.0)
#define ll long long
#define endl "\n"

void file(){
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
}
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}


ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int dx[] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
char dir[] = { 'U', 'R', 'D', 'L' };
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
//474,365
//7000
const int N = 2e5 + 5, mod = 1e9 + 7;
vector<int> a;
bool mem[4005][16005], vis[4005][16005];
int n;
bool ok;
bool solve(int i, int num){
	if (i == a.size())return num == n;
	bool&ret = mem[i][num];
	if (vis[i][num])return ret;
	vis[i][num] = 1;
	ret = solve(i + 1, num + a[i]);
	if (i||ok)ret|= solve(i + 1, num - a[i]);
	return ret;
}
int main()
{
	/***  بسم الله الرحمن الرحيم   ***/
	//file();
	fast();

	string s;
	cin >> s;
	vector<int> v(1, 0);

	for (int i = 0; i < s.size(); i++)
	if (s[i] == 'T')v.push_back(0);
	else
		v.back()++;

	int x, y;
	cin >> x >> y;
	n = x + 8001;

	for (int i = 0; i < v.size(); i++)
	if (i % 2 == 0)
		a.push_back(v[i]);
	if (!solve(0, 8001))return cout << "No", 0;

	memset(vis, 0, sizeof vis);
	a.clear();
	n = y + 8001;
	ok = 1;
	for (int i = 0; i < v.size(); i++)
	if (i % 2)
		a.push_back(v[i]);
	if (!solve(0, 8001))return cout << "No", 0;

	cout << "Yes";

}