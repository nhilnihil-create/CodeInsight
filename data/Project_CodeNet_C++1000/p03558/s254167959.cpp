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
int K;

//無限ループしないように、1度見たところは2度は見ない
vector<vector<bool>> went;




//サブ関数
//入力
void input()
{
	cin >> K;
	went = vector<vector<bool>>(50, vector<bool>(K, false));
}


//計算
void calc()
{
	// first:dist, second:remainder(mod K)
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(1, 1));
	while (!pq.empty())
	{
		//距離最短の数値を一つ取り出す
		auto now = pq.top(); pq.pop();

		//移動済みなら無視
		if (now.first >= 50)continue;
		if (went[now.first][now.second])continue;
		went[now.first][now.second] = true;

		//数字を昇順に、そして一意に変化させるとすると、以下の二通りの操作に帰着できる
		//① 1を足す
		//このとき、数字の総和は1増え、mod K は1増える
		auto next = make_pair(now.first + 1, (now.second + 1) % K);
		pq.push(next);
		//②10倍する
		//このとき、数字の総和は増えず、modKは10倍になる
		auto next2 = make_pair(now.first, (now.second * 10) % K);
		pq.push(next2);
	}
}


//出力
void output()
{
	REP(i, 50) {
		if (went[i][0]) {
			cout << i << endl;
			return;
		}
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
	output();
	debug();
	
	return 0;
}
