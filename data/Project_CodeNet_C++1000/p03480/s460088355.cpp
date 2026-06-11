#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

string s;
int n;

bool possible( int k ){
	bool res = true;
	for( int i = n-k; i < k-1; ++i ){
		if( s[i] != s[i+1] ) res = false;
	}
	return res;
}

int main(){
	cin >> s;
 	n = s.l_ength();
  	int ok = 1;
	int ng = n+1;
	while( ng-ok > 1 ){
		int mid = (ok+ng)/2;
		if( possible(mid) ){
			ok = mid;
		} else {
			ng = mid;
		}
	}
	cout << ok << endl;
}