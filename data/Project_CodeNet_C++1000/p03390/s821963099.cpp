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
#include<fstream>

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
int Q;
vector<pair<LL, LL>> ab;






//サブ関数
//入力
void input()
{
}


//計算
void calc(pair<LL,LL> now)
{
	LL A = now.first;
	LL B = now.second;
	LL score = A * B - 1;
	LL ans;
	LL base = score;

	base = sqrtl(base) - 10;
	if (base < 0)base = 0;
	while (base*(base + 1) <= score)base++;
	ans = (base - 1) * 2;
	//cerr << "first:" << ans << endl;
	/*
	while (true) {
		LL l = floor(1.*score / base);
		LL r = floor(1.*score / (base + 1));
		if (l > r)break;
		if (l == r) {
			ans++;
			break;
		}
		ans += 2;
		base++;
	}
	*/
	//cerr << "now" << ans << endl;
	//解がほぼ同じなら、そもそもない？
	
	LL l = min(A, B);
	LL r = max(A, B);
	LL see = floor(1.*score / l);

	//cerr << "score" << score << endl;
	//cerr << "l    " << l << endl;
	//cerr << "see" << see << endl;
	ans--;
	if (base*base <= score)ans++;
	if (A == B)ans++;
	//cerr << "second:";
	cout << ans << endl;
}


//出力
void output()
{

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
	cin >> Q;
	REP(i, Q) {
		LL l, r;
		cin >> l >> r;
		ab.push_back(make_pair(l, r));
	}
	for (auto now : ab) {
		calc(now);
	}
	debug();
	
	return 0;
}

