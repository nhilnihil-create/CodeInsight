#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n,x;
	cin >> n >> x;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	sort(a.begin(),a.end());
	int sum = x;
	int counts = 0;
	rep(i,n){
		if(sum < a[i]) {
			cout << counts << endl;
			return 0;;
		}
		sum -= a[i];
		counts++;
	}
	if(sum == 0) cout << counts << endl;
	else if(counts == 0) cout << 0 << endl;
	else cout << counts -1 << endl;
}