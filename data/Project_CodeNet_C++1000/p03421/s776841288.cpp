#include<iostream>
#include <list>
#include<stack>
#include<queue>
#include <vector>
#include <set>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>
#include <functional>

#define FOR(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define LL long long
#define CLR(a) memset((a),0,sizeof(a))
#define SZ(x) (int((x).size()))
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<<str<<endl
using namespace std;

const LL MOD = 1000000007;// 10^9+7
const int INF = (1 << 30);


//変数
LL N, A, B;
vector<LL> ans_;





//サブ関数
//入力
void input()
{
	cin >> N >> A >> B;
}

bool can(LL N, LL A, LL B) {
	if (A + B <= N + 1 && A*B >= N)return true;
	else return false;
}

//計算
void calc()
{
	if (!can(N, A, B)) {
		cout << "-1" << endl;
	}
	else if (min(A, B) == 1) {
		if (B == 1) {
			REP(i, N)cout << i + 1 << " ";
		}
		else {
			REP(i, N)cout << N - i << " ";
		}
		cout << endl;
	}
	else {
		vector<LL> res(A, B);
		LL sum = A * B;
		LL i = A;

		while (sum > N) {
			i--;
			res[i] = 1;
			sum -= B - 1;
		}
		while (sum < N) {
			res[i]++;
			sum++;
		}
		REP(i, A - 1)res[i + 1] += res[i];
		for (LL j = res[0]; j > 0; j--)cout << j << " ";
		REP(i, A - 1)
			for (LL j = res[i + 1]; j > res[i]; j--)cout << j << " ";
		cout << endl;

		/*
		vector<vector<int>> ans(B);
		int cnt = 1;
		REP(i, B) {
			REP(j, res[i]) {
				ans[i].push_back(cnt);
				cnt++;
			}
		}
		for (auto v : ans) {
			while (v.size() > 0) {
				cout << v.back() << " ";
				v.pop_back();
			}
		}
		cout << endl;
		*/
	}
}

//デバッグ
void debug()
{
	int N;
	cin>>N;
}


//メイン関数
int main()
{
	input();
	calc();
	debug();
	
	return 0;
}
