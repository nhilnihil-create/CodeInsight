#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)

int main(){
	int n;
	cin >> n;
	
	int ma = 0;
	int mi = __INT_MAX__;
	rep(i,n){
		int a;
		cin >> a;
		ma = max(ma, a);
		mi = min(mi, a);
	}
	cout << ma - mi << endl;
}