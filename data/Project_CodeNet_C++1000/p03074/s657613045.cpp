#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	string S;
	cin >> S;

	vector<int> Nums;
	int now = 1; //今見ている数
	int cnt = 0; //nowがいくつ並んでいるか
	for (int i = 0; i < N; i++)
	{
		if (S[i] == (char)('0' + now)) cnt++;
		else {
			Nums.push_back(cnt);
			now = 1 - now; //0と1を切り替える時の計算 now ^= 1;
			cnt = 1; //新しいのをカウントし始める
		}
	}
	if (cnt != 0) Nums.push_back(cnt);

	//1-0-1-0-1-0-1って感じの配列が欲しい
	//1-0-1-0みたいに0で終わってたら、適当に１つ足す
	if (Nums.size() % 2 == 0) Nums.push_back(0);

	int Add = 2 * K + 1;

	//累積和を作る
	// 0 1 2 3 4 5 6
	//  0 1 2 3 4 5

	vector<int> sum(Nums.size() + 1);
	for (int i = 0; i < Nums.size(); i++)
	{
		sum[i + 1] = sum[i] + Nums[i];
	}


	int ans = 0;
	//1-0-1...の1から始めるので、偶数番目だけ見る
	for (int i = 0; i < Nums.size(); i += 2)
	{
		//次のleft, rightを計算する [left, right)
		int left = i;
		int right = min(i + Add, (int)Nums.size());
		int tmp = sum[right] - sum[left];

		ans = max(tmp, ans);
	}

	cout << ans << endl;
}
