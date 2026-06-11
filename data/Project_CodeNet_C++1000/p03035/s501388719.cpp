#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<unordered_map>
#pragma warning(disable: 4996)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define PI 3.141592653589793

using namespace std;
using ll = long long;


int main() {

	int a, b;

	cin >>a >> b;

	if (a >= 13)cout << b;
	else if (a >= 6 && a <= 12)cout << b / 2;
	else cout << '0' << endl;

	return 0;
}