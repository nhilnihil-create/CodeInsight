#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <climits>
#include <cmath>
#include <utility>
#include <iomanip>
//#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long int;
//// 任意長整数型
//namespace mp = boost::multiprecision;
//using Bint = mp::cpp_int;



int main(int argc, char *argv[])
{
	int N, K;
	//input
	cin >> N >> K;

	vector<ll> x, y;
	for (int i = 0; i < N; ++i){
		ll xi, yi;
		cin >> xi >> yi;
		x.push_back(xi);
		y.push_back(yi);
	}


	//calc
	ll min_area = LLONG_MAX;
	for (int i = 0; i < N; i++){//x1
		for (int j = 0; j < N; j++){//x2
			for (int k = 0; k < N; k++){//y1
				for (int l = 0; l < N; l++){//y2
					int count_point_in_rect = 0;
					for (int m = 0; m < N; m++){
						if (min(x[i], x[j]) <= x[m] && x[m] <= max(x[i], x[j]) &&
							min(y[k], y[l]) <= y[m] && y[m] <= max(y[k], y[l])){
							count_point_in_rect++;
						}
					}

					if (K <= count_point_in_rect){
						ll current_area = abs(x[i] - x[j]) * abs(y[k] - y[l]);
						if (current_area != 0 && current_area < min_area){
							min_area = current_area;
						}
					}
				}
			}
		}
	}


	//ans
	cout << min_area << endl;

	return 0;
}
