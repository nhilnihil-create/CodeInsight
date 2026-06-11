// Never Give Up!
#include <stdio.h>
#include <iostream>
#include <limits>
#include <cstdint>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <bitset>
#include <array>
#include <string.h>
#include <stack>
#include <queue>
#include <stdint.h>
#include <sstream>
#include <map>
#include <set>
#include <locale>
#define mem(x, y) memset(x, y, sizeof x);
#define __STDC_LIMIT_MACROS
#define fio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn = 1e5 + 5, INF = 1e9;
int n , a[maxn] , mxn = 0 , mxr , dr = INF , _i;
int main(){     
      
	fio;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] > mxn){
			mxn = a[i];
			_i = i;
		}
	}

	for(int i = 0; i < n; i++){
		if(abs(a[i] - mxn/2) < dr && i != _i){
			dr = abs(a[i] - mxn/2);
			mxr = a[i];
		}
	}
	
	

	cout << mxn << " " << mxr << endl;




    	return 0;
}