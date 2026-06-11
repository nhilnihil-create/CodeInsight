#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<cmath>
#include<numeric>
#include<vector>
#include<algorithm>
#include<string>
#include<deque>
#include<stack>
#include<map>
#include<cstring>
#include<random>
#include<queue>
#include<iterator>
#include<bitset>
#include<unordered_set>
#include<set>

using namespace std;
#define ll long long
#define endl "\n"
const int dx[] = { -1 , -1 , -1 , 0 , 0 , 0 , 1 , 1 , 1 };
const int dy[] = { -1 , 0 , 1 , -1 , 0 , 1 , -1 , 0 , 1 };
const ll integer = pow(2, 32) - 1; // 4294967295
#define N 8010000
#define TC int t;cin>>t;for(int T=1;T<=t;T++)
#define mod 1000000007
#define PI acos(-1)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define clr(v, d) memset(v, d, sizeof(v)) 
void AIA() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
bool isprime(ll n) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0)return 0;
	}
	return (n != 1);
}
ll gcd(ll x, ll y)
{
	return (y == 0 ? x : gcd(y, x % y));
}
ll lcm(ll x, ll y) {
	return (x * y) / gcd(x, y);
}
/*
 _____________              __                ___        ___       ___________________________     ____        ____
|             |            /\ \              |   |      |   |     |                           |    \   \      /   /
|   __________|           / /\ \             |   |      |   |     |      _____      _____     |     \   \    /   /
|  |                     / /  \ \            |   |      |   |     |     |     |    |     |    |      \   \  /   /
|  |                    / /    \ \           |   |      |   |     |     |     |    |     |    |       \   \/   /
|  |______             / /      \ \          |   |______|   |     |     |     |    |     |    |        \      /
|         |           / /        \ \         |              |     |     |     |    |     |    |         \    /
|   ______|          / /          \ \        |    ______    |     |     |     |    |     |    |          |  |
|  |                / /============\ \       |   |      |   |     |     |     |    |     |    |          |  |
|  |               / /==============\ \      |   |      |   |     |     |     |    |     |    |          |  |
|  |              / /                \ \     |   |      |   |     |     |     |    |     |    |          |  |
|  |             / /                  \ \    |   |      |   |     |     |     |    |     |    |          |  |
|__|            /_/                    \_\   |___|      |___|     |_____|     |____|     |____|          |__|

										  <<<<<<<<<<< NEVER GIVE UP !! >>>>>>>>>>>
										<<<<<<<< YOU CAN DO IT IF YOU WANT !! >>>>>>>>
										 <<<<<<<<< BELIEVE IN YOURSELF !! >>>>>>>>>
*/
int n, x, k, m, cnt = 0;
vector<int>v1, v2, v3;
int mem[500007][5];
int solve(int i, int type) {
	if (i == n) {
		return 0;
	}
	int &cost = mem[i][type];

	if (cost != -1) {
		return cost;
	}

	cost = -1e6;

	if (type != 1) {
		cost = max(cost, v1[i] + solve(i + 1, 1));
	}
	if (type != 2) {
		cost = max(cost, v2[i] + solve(i + 1, 2));
	}
	if (type != 3) {
		cost = max(cost, v3[i] + solve(i + 1, 3));
	}
	return cost;
}
int main()
{
	//cout<<fixed<<setprecision(20);
	//freopen("Input.txt.txt", "r", stdin);
	//freopen("Output.txt.txt", "w", stdout);
	AIA();
	cin >> n;
	v1.resize(n);
	v2.resize(n);
	v3.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v1[i] >> v2[i] >> v3[i];
	}
	clr(mem, -1);
	cout << solve(0, 4);
	return 0;
}
