#include <iostream>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;
// scanf
#pragma warning(disable: 4996)
// v:vector  type:型  order:greater or less
#define _sort(v,type,order) do { sort(v.begin(),v.end(),order<type>()); } while(0)
// v:vector  default_value:初期値
#define _sum(v,default_value) accumulate(v.begin(),v.end(),default_value )
// 丸め
#define _round(v) round(v)
// 2乗 / 3乗
#define _square(v) pow(v,2)
#define _cube(v)   pow(v,3)
// 大小判定
#define _max(x,y) max(x,y)
#define _min(x,y) min(x,y)

int main()
{
	string s;
	cin >> s;

	s[0] = '2';
	s[1] = '0';
	s[2] = '1';
	s[3] = '8';
	printf("%s\n",s.c_str());
	return 0;

	//	std::cout << "Hello World!\n"; 
}
