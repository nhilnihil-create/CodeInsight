#include <iostream>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n;i++)
int main(void) {
	int a, b;cin >> a >> b;
	int s = b - a, d = s * (s + 1) / 2;
	cout << d - b << endl;
}