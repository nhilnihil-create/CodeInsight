#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)



int main(){
	long long n;
	cin >> n;
	vector<long long> a(n+1);
	
	a[0]=2;
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i] = a[i-1] + a[i-2];
	}
	
	cout << a[n] << endl;
	
	return 0;
	
}