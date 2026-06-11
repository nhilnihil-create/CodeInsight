#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<set>
#include<string>
typedef long long ll;
using namespace std;
#define INF (1 << 30)
#define INFLL (1LL << 60)
#define rep(i, n) for(int i=0; i<(n); ++i)


int main()
{
	int N; string S; cin >> N >> S;
	int hs = N;	//half S.size()
	vector<pair<string, string>> br;

	//文字列の半分までのパターンを全列挙
	rep(i, 1 << hs) {
		string b = "", r = "";
		//j番目のビットが立っているか
		rep(j, hs) {
			if (1 << j & i) b += S[j];
			else r += S[j];
		}
		reverse(r.begin(), r.end());
		br.emplace_back(b, r);
	}
	sort(br.begin(), br.end());

	ll ans = 0;
	//残り半分の文字パターンを全列挙する
	rep(i, 1 << hs) {
		string b = "", r = "";
		rep(j, hs) {
			if (1 << j & i) b += S[hs + j];
			else r += S[hs + j];
		}
		reverse(r.begin(), r.end());
		//(red, blue)と一致する組を、br(blue, red)から探す
		auto p = make_pair(r, b);
		auto it = lower_bound(br.begin(), br.end(), p);
		auto it2 = upper_bound(br.begin(), br.end(), p);
		ans += distance(it, it2);	//同じ文字列が複数あるときもカウントする
	}
	cout << ans << "\n";
	return 0;
}
