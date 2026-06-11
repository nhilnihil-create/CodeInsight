#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int n, m;

int main(void){
	cin >> n >> m;
	vector<int> favo(m+1);
	rep(i, n){
		int k;
		cin >> k;
		rep(j, k){
			int a;
			cin >> a;
			favo[a]++;
		}
	}
	int ans = 0;
	rep(i, m+1){
		if(favo[i]==n) ans++;
	}
	cout << ans << endl;
	return 0;
}
