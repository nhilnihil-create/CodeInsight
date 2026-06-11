#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
char s[4] = {'L','R','U','D'}, t[4] = {'R','L','D','U'};

int main()
{
	int H,W,N;
	cin >> H >> W >> N;
	int sr,sc;
	cin >> sr >> sc;
	string S,T;
	cin >> S >> T;
	bool ans = true;
	int temp = sc;
	rep(i,N)
	{
		if (S[i] == 'L')
		{
			temp--;
			if (temp == 0) ans = false;
		}
		if (T[i] == 'R' && temp != W)
		{
			temp++;
		}
	}
	temp = sc;
	rep(i,N)
	{
		if (S[i] == 'R')
		{
			temp++;
			if (temp == W+1) ans = false;
		}
		if (T[i] == 'L' && temp != 1)
		{
			temp--;
		}
	}
	temp = sr;
	rep(i,N)
	{
		if (S[i] == 'U')
		{
			temp--;
			if (temp == 0) ans = false;
		}
		if (T[i] == 'D' && temp != H)
		{
			temp++;
		}
	}
	temp = sr;
	rep(i,N)
	{
		if (S[i] == 'D')
		{
			temp++;
			if (temp == H+1) ans = false;
		}
		if (T[i] == 'U' && temp != 1)
		{
			temp--;
		}
	}
	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}