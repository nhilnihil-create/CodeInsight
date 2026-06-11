#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979

int main()
{
	string s;
	int minDiff = 1000;	//753からの最小の差
	int xSize = 3;		//比較する文字列Xは3文字
	int number = 753;	//比較対象の数字
	cin >> s;			//入力を受け取る

	rep(i, s.length() - xSize + 1)
	{
		int diff = abs(stoi(s.substr(i, xSize)) - number);	//選んだ数字との差の絶対値を計算
		if (diff < minDiff) minDiff = diff;					//もし753との差が最小なら保存
	}
	cout << minDiff << endl;
	return 0;
}