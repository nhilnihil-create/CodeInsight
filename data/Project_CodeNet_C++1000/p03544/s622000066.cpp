#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long ll;

int main()
{
	int n;
	cin>>n;
	vector<ll> L(87);
	L[0] = 2;
	L[1] = 1;
	for(int i = 2; i <= n; i++){
		L[i] = L[i-1] + L[i-2];
	}
	cout<<L[n]<<endl;
	return 0;
}

