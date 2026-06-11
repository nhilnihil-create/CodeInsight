#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using Pt = pair<int, int>;

void AGC033B()
{
	int H, W, N;
	cin >> H >> W >> N;
	int sr, sc;
	cin >> sr >> sc;
	string S, T;
	cin >> S;
	cin >> T;

	int x = sc;
	for (int i = 0; i < N; ++i)
	{
		if (S[i] == 'R')
			++x;
		if (x > W)
		{
			cout << "NO" << endl;
			return;
		}
		if (x > 1 && T[i] == 'L')
			--x;
	}
	x = sc;
	for (int i = 0; i < N; ++i)
	{
		if (S[i] == 'L')
			--x;
		if (x < 1)
		{
			cout << "NO" << endl;
			return;
		}
		if (x < W && T[i] == 'R')
			++x;
	}

	x = sr;
	for (int i = 0; i < N; ++i)
	{
		if (S[i] == 'D')
			++x;
		if (x > H)
		{
			cout << "NO" << endl;
			return;
		}
		if (x > 1 && T[i] == 'U')
			--x;
	}

	x = sr;
	for (int i = 0; i < N; ++i)
	{
		if (S[i] == 'U')
			--x;
		if (x < 1)
		{
			cout << "NO" << endl;
			return;
		}
		if (x < H && T[i] == 'D')
			++x;
	}
	cout << "YES" << endl;
}
int main()
{
	AGC033B();
	return 0;
}