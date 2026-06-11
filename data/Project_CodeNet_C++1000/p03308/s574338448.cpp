#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	int maxim = 0;
	int minimum = 1e9;
	rep(i,n){
		maxim = max(maxim,a[i]);
		minimum = min(minimum,a[i]);
	}
	cout << maxim - minimum << endl;
}