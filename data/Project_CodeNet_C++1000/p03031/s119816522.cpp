#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> Km(M);
	vector<vector<int>> Smk(M, vector<int>(10, -1));
	vector<int> Pi(M);
	
	rep(i, M)
	{
		cin >> Km[i];
		rep(j, Km[i])
		{
			cin >> Smk[i][j];
		}
	}

	rep(i, M) cin >> Pi[i];

	int ans = 0;
	for (int i = 0; i < pow(2, N); ++i)
	{
		vector<int> Sc(M, 0);
		// j : 調べるスイッチのビット位置
		for (int j = 0; j < N; ++j)
		{
			if ((i >> j & 1) == 1)
			{
				// k番目の電球を調べる
				for (int k = 0; k < M; ++k)
				{
					for (int q = 0; q < Km[k]; ++q)
					{
						if (Smk[k][q] == (j+1))
						{
							Sc[k] += 1;
						}
					}
				}
			}
		}

		//組み合わせ確認
		int cnt = 0;
		for (int ck = 0; ck < M; ++ck)
		{
			if (Pi[ck] == 0 && Sc[ck] % 2 == 0)
			{
				cnt += 1;
			}
			else if (Pi[ck] == 1 && Sc[ck] % 2 == 1)
			{
				cnt += 1;
			}
		}
		if (cnt == M) ans += 1;
	}

	cout << ans << endl;
	return 0;
}