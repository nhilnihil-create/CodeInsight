#include <bits/stdc++.h>

#define F first 
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 200010, M = 110;

int n;
int cnt[M];

int main()
{
	cin >> n;
	for (int i = 2; i <= n; i ++ )
	{
		int t = i;
		for (int j = 2; j <= t / j; j ++ )
			while (t % j == 0)
			{
				cnt[j] ++ ;
				t /= j;
			}
		if (t > 1) cnt[t] ++ ;
	}
	
	int res = 0;
	for (int i = 2; i < M; i ++ )
		if (cnt[i] >= 74)
			res ++ ;
	
	for (int i = 2; i < M; i ++ )
		for (int j = 2; j < M; j ++ )
			if (cnt[i] >= 2 && cnt[j] >= 24 && i != j)
				res ++ ;
	
	for (int i = 2; i < M; i ++ )
		for (int j = 2; j < M; j ++ )
			if (cnt[i] >= 4 && cnt[j] >= 14 && i != j)
				res ++ ;
	
	for (int i = 2; i < M; i ++ )
		for (int j = 2; j < M; j ++ )
			for (int k = 2; k < j; k ++ )
				if (cnt[i] >= 2 && cnt[j] >= 4 && cnt[k] >= 4)
					if (i != j && j != k && k != i)
						res ++ ;
	
	cout << res << endl;
    return 0;
}