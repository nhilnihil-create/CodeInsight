#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	if (s.size() == 3)
	{
		cout << s.at(2) << s.at(1) << s.at(0) << endl;
	}
	else
	{
		cout << s << endl;
	}
	return 0;
}
/*
死のマウス
.　　あり許せん！
　　　∧＿＿∧
　|| （＃｀Д´ ） ||
　|| ( |　 　| | |||
　从| |　 　| |从从
￣) ⊂ノ￣￣!_つ￣て
　フヘ(　　　　ヽヘ(＼

*/