#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a.at(i);
	ll ma = 0;
	int u = min(n, k);
	for(int i=0; i<=u; i++){
		for(int j=0; j<i; j++){
			if(i+j > k) continue;
			rep(l, i+1){
//				cout << i << ' ' << j << ' ' << l << ':';
				vector<int> pu(i);
				rep(ll, i){
					pu.at(ll) = a.at((n-i+ll+l)%n);
				}
				sort(pu.begin(), pu.end());
				reverse(pu.begin(), pu.end());
				ll sum = 0;
				rep(ll, i-j){
					sum += pu.at(ll);
//					cout << pu.at(ll) << ' ';
				}
//				cout << endl;
				if(sum > ma) ma = sum;
				
			}
		}
	}
	cout << ma << endl;
	return 0;
}