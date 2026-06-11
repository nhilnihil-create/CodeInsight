#include<iostream>

#include <vector>
#include <list>
#include<stack>
#include<queue>
#include<array>

#include <set>
#include<map>

#include<string>
#include<stdlib.h>

#include<algorithm>
#include <functional>
#include<math.h>

#include<fstream>
#include<iomanip>
#include<assert.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define FOR(k,m,n) for(ll (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<<str<<endl

constexpr int INF = 100000;
constexpr ll INFL = (1ll << 60);
constexpr ll MOD = 1000000007;// 10^9+7


							  //変数
int N;
vector<pair<ll, ll>> xy;






//サブ関数
//入力
void input()
{
	cin >> N;
	REP(i, N) {
		ll a, b;
		cin >> a >> b;
		xy.push_back({ a,b });
	}
}


//計算
void calc()
{
	bool even = ((xy[0].first + xy[0].second + INFL) % 2 == 0);
	for (auto p : xy) {
		if (even) {
			if ((p.first + p.second + INFL) % 2 != 0) { cout << -1 << endl; return; }
		}
		else {
			if ((p.first + p.second + INFL) % 2 != 1) { cout << -1 << endl; return; }
		}
	}
	constexpr int m = 40;
	cout << m << endl;
	ll D = (even ? 2 : 1);
	REP(i, m - 8) {
		D *= 2;
	}
	D /= 2;

	ll d = D;
	REP(i, m - 8) {
		cout << d << " ";
		d /= 2;
	}
	REP(i, 8)cout << "1 ";
	cout << endl;

	for (auto p : xy) {
		ll x = p.first;
		ll y = p.second;
		d = D;
		REP(i, m) {
			ll u = y - x;
			ll v = x + y;
			if (u >= 0) {
				if (v >= 0) {
					cout << "U";
					y -= d;
				}
				else {
					cout << "L";
					x += d;
				}
			}
			else {
				if (v >= 0) {
					cout << "R";
					x -= d;
				}
				else {
					cout << "D";
					y += d;
				}
			}
			if (d > 1)d /= 2;
			//cerr << " " << d << endl;
		}

		//cerr <<"res"<< x << " " << y << endl;
		cout << endl;
	}
}


//出力
void output()
{

}


//デバッグ
void debug()
{
	int N;
	cin >> N;
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
