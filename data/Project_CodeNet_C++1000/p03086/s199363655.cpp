// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int size = s.length();
	vector<int> v;
	

	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			char z = s.at(j);
			if (z == 'A' || z == 'T' || z == 'G' || z == 'C') count++;
			else break;
		}
		v.push_back(count);
		count = 0;
	}

	vector<int>::iterator itr = max_element(v.begin(), v.end());
	size_t ind = distance(v.begin(), itr);

	cout << v[ind] << endl;
	return 0;

}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー
