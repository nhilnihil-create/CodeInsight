#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> b[i];
	int maxim = 0;
	rep(i,n){
		int sum = 0;
		rep(j,i+1){
			sum += a[j];
		}
		for(int k = i; k < n; k++){
			sum += b[k];
		}
		maxim = max(maxim, sum);
	}
	cout << maxim << endl;
}