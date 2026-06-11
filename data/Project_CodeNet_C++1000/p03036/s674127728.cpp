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

ll X[13];

int main() {

	int r, D;

	cin >> r >> D >> X[0];

	for(int i=1;i<=10;i++){
	
		X[i] = r * X[i - 1] - D;
		cout << X[i] << endl;
	}

	return 0;
}