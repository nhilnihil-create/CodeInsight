#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	string s, t;
	cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	reverse(t.begin(), t.end());
	//第一引数 < 第二引数 なら　マイナス
	//第一引数 > 第二引数 なら　プラス
	if (strcmp(s.c_str(), t.c_str()) < 0) {
		printf("Yes");
	}
	else {
		printf("No");
	}
}