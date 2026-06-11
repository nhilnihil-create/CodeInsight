#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n;
map<LL, PII> S;
vector<PII> ans;
LL offset;

int main()
{
	scanf("%d", &n);
	rep(i, n) {
		LL d;
		scanf("%lld", &d);
		S[d] = MP(1, i + 1);
	}
	while(S.size() >= 2) {
		pair<LL, PII> cur = *S.rbegin();
		S.erase(cur.first);
		LL nd = cur.first - n + 2 * cur.second.first;
		if(S.find(nd) == S.end()) {
			printf("-1\n");
			return 0;
		}
		S[nd].first += cur.second.first;
		offset += cur.second.first;
		ans.push_back(MP(cur.second.second, S[nd].second));
	}
	if(S.begin()->first != offset) printf("-1\n");
	else rep(i, ans.size()) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}