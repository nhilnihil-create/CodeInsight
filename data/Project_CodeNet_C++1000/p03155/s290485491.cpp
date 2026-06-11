#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <stdio.h>

using namespace std;

//typedefリスト
typedef vector<long long int> vint;
typedef vector<string> vstr;
typedef long long int llint;



int main(void) {
	llint N, H, W, ans1, ans2;
	cin >> N >> H >> W;
	ans1 = (N - H) + 1;
	
	ans2 = (N - W) + 1;
	
	cout << ans1*ans2 << endl;
}
