#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N;
	cin >> N;
	vector<int> a(N);
	double sum;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	sum /= N;
	int ans;
	double tmp = 100;
	for(int i = 0; i < N; ++i){
		if(tmp > abs(sum - a[i])) {
			tmp = abs(sum - a[i]);
			ans = i;
		}
	}
	cout << ans << endl;

}








