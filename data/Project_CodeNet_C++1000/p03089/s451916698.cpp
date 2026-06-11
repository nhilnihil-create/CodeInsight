#include<algorithm>
#include<cmath>
#include<climits>
#include<cstdio>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main()
{
	int N;
	cin >> N;

	vector<int> b(N);
	rep(i, N) cin >> b[i];

	vector<int> backup;

	//i:回数のループ
	revrep(i, N)
	{
		bool flg = true;

		//j:使える数字のループ
		//大きい数字から消す
		revrep(j, i + 1)
		{
			//k:数列の番号のループ
			auto itr = find(all(b), j + 1);

			if (itr == b.begin() + j)
			{
				backup.push_back(*itr);
				b.erase(itr);
				flg = false;
				break;
			}
		}

		//要素を削除できない場合は不可
		if (flg)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	revrep(i, backup.size())
	{
		cout << backup[i] << endl;
	}

	return 0;
}