#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
#include <bitset>
#include <map>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef queue<int, int> qii;
typedef pair<int, int> pii;

#define PI 3.14159265359
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repz(i,n) rep(i,0,n)

//int型を受け取ってその桁数を返す
int check_digits(int n) {
	int digits = 0;
	while (n != 0) {
		n /= 10;
		digits++;
	}
	return digits;
}


//最大公約数を返す関数
int gcd(int n, int m) {
	while (n != 0) {
		if (n < m) swap(n, m);
		n = n % m;
	}
	return m;
}


//2点間の距離を返す
float dis(int x1, int y1, int x2, int y2) {
	return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
}


int main() {
	int a, b;
	cin >> a >> b;
	int c = b - a;

	vi memo(1200, 0);
	for (int i = 1; i <= c; ++i) {
		memo[i] += i + memo[i-1];
	}
	//cout << c << endl;
	//cout << memo[c] << endl;
	cout << memo[c] - b << endl;
	
	
	system("pause");
	return 0;
}