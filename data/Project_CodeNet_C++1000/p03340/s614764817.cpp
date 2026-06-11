#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n){
		cin >> a.at(i);
	}
	ll ans = 0;
	ll sum = 1;
	int ts = 0;
	for(int i=0; i<n; i++){
		int t = ts;
		sum--;
		int f = 0;
		for(int j=i+sum; j<n; j++){
			t = t ^ a.at(j);
			ts += a.at(j);
			if(t != ts){
				f = 1;
				ts -= a.at(j);
				ts -= a.at(j-sum);
				break;
			}
			if(f == 1) break;
			sum++;
		}
		ans += sum;
	}
	cout << ans << endl;
	return 0;
}