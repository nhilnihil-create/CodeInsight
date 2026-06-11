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
	uint32_t n;
	cin >> n;
	vector<int32_t> v(100000,0);

	int32_t temp;
	int32_t max_elem = 0;
	uint32_t result = 0;
	for (uint32_t i = 0; i < n; i++) {
		cin >> temp;
		if (temp > 100000) {
			result++;
			continue;
		}
		v[temp]++;
		if (temp > max_elem) { max_elem = temp; }
	}
	for (int32_t i = 1; i <= max_elem; i++) {
		if (!v[i]) { continue; }
		if (i == v[i]) { continue; }
		result += i > v[i] ? v[i] : v[i] - i;
	}

	cout << result;

	return 0;
	//	std::cout << "Hello World!\n"; 
}
