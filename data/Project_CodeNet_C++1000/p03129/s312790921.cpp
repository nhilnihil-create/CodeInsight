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
	int N,K,num;
	cin >> N >> K;
	if (N % 2 == 0)num = N / 2;
	else num = N / 2 + 1;

	if (num >= K)cout << "YES" << endl;
	else cout << "NO" << endl;
}