#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
using ll = long long;
int main()
{
	int n;
	scanf("%d", &n);
	vector<ll> a(n);
	rep(i, n) scanf("%lld", &a[i]);

	//累積和 n + 1なのは 累積和の図を思い出すこと
	vector<ll> s(n + 1, 0);
	rep(i, n) s[i + 1] = s[i] + a[i]; //累積和公式
	// rep(i, n + 1) cout << s[i] << endl;

	map<ll, ll> nums; //sの中にどの数字が何個あるか連想配列で確認
	rep(i, n + 1) nums[s[i]]++;
	// for (auto i : nums) cout << i.first << " " << i.second << endl;

	// 集計処理
	ll ans = 0;
	for (auto i : nums) //nums分繰り返す
	{
		ll num = i.second; //numに特定の数字(nums = i)が何個あったか入れる
		ans += num * (num - 1) / 2; //累積和の始点と終点の2点が何通り作れるかansに追加してく
	}
	printf("%lld\n", ans);
	return 0;
}