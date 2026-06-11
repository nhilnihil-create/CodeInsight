#include <iostream>
#include <vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<set>
#include<iterator>
using ll = long long;
using namespace std;
ll N;
vector<string> S(300),T(300);
int main()
{
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		cin >> S[i];
	}
	for (size_t i = 0; i < N; i++)
	{
		T[i] = S[i] + S[i].substr(0,S[i].size()-1);
	}
	ll ans = 0;
	for (size_t i = 0; i < N; i++)
	{
		bool f = true;
		for (int j = 0; j < N; j++)
		{
			for (size_t k = j+1; k < N; k++)
			{
				if (T[j][k + i] != T[k][j + i]) {
					f = false;
					goto END;
				}
			}
		}
	END:
		if (f) {
			ans += N;
		}
	}
	cout << ans << endl;
}