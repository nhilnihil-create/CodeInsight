#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);

	int N,X; cin>>N>>X;
	vector<int> m(N);
	
	int sum=0,ming=1000;
	rep(i,N){
		int x; cin>>x;
		sum += x;
		ming = min(ming, x);
	}

	int ans = N + (X-sum)/ming;
	cout << ans << endl;

}
