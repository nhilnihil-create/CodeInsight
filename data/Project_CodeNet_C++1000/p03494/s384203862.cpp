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
	int n, count = 0;
	bool flag = true;							//奇数が1つでも含まれているとfalse
	cin >> n;
	vector<int> a(n);							//nこの要素を持つ配列を定義

	rep(i, n)
	{
		cin >> a[i];							//入力を受け取る
		if (a[i] % 2 != 0) flag = false;		//もし入力時点で奇数があれば計算は何も行われない
	}

	while (flag)
	{
		count++;								//計算できた回数
		rep(i, n)
		{
			a[i] /= 2;							//2で割る
			if (a[i] % 2 != 0) flag = false;	//割った後に奇数になったらこのループまでで止める
		}
	}
	
	cout << count << endl;
}