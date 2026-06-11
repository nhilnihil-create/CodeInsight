// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int count = 0;
	int divisors = 0;
	for (int i = 1; 2 * i + 1 <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if ((2 * i + 1) % (2 * j + 1) == 0) divisors++;
			if (divisors > 8) break;
		}
		if (divisors == 8) count++;
		divisors = 0;
	}
	cout << count << endl;
	return 0;

}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー
