// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int a;
	int b;
	int k;
	cin >> a >> b >> k;

	vector<int> v;

	// odd numbers
	for (int i = 1; (i <= a && i <= b); i++) {
		if (a % i == 0 && b % i == 0) {
			v.push_back(i);
		}
	}
	sort(v.begin(), v.end(), greater<int>());

	int vsize = v.size();
	int ans = v.at(k - 1);

	cout << ans << endl;
	return 0;

}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー
