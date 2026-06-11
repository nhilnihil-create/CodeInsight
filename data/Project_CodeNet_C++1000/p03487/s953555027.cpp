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
// 2乗 / 3乗  default_value:初期値
#define _square(v) pow(v,2)
#define _cube(v)   pow(v,3)
// 大小判定
#define _max(x,y) max(x,y)
#define _min(x,y) min(x,y)

int main()
{
	uint32_t n;
	cin >> n;

	vector<uint32_t> v(n);

	for (size_t i = 0; i < v.size(); i++) {
		cin >> v[i];
	}
	_sort(v,uint32_t,less);

	uint32_t result = 0;
	for (size_t i = 0; i < v.size(); i++) {

		size_t j;
		for (j = i+1; j < v.size(); j++) {
			if (v[i] == v[j]) { continue; }
			break;
		}
		if (j - i != v[i]) {
			result += ((j - i) < v[i] ? (j - i) : ((j - i) - v[i]));
		}
		i = j-1;
	}

	cout << result;

	return 0;
	//	std::cout << "Hello World!\n"; 
}
