#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)

int main(){
	int n,x;
	cin >> n >> x;
	vector<int> m(n);
	
	int mi = __INT_MAX__;
	int total = 0;
	rep(i,n){
		cin >> m.at(i);
		mi = min(mi, m.at(i));
		x  -= m.at(i);
	}

	int count = x/mi;

	cout << n+count << endl;

}