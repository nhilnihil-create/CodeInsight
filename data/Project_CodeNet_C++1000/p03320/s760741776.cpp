#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ll long long
#define debug(a) cout<<#a<<": ";for(auto i:a)cout<<i<<" ";cout<<endl;
#define trace(a) cout<<#a<<": "<<a<< endl
#define int ll
int a[N];
signed main() {
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	int i,j,k,l,m,n,t;
	cin >> n;
	set<pair<double,int>> se;
	for(i = 1;i < 10;i++) {
		int val = i;
		int sum = 0;
		while(val) {
			sum += val%10;
			val /= 10;
		}
		double an = i;
		an /= sum;
		se.insert({an,i});
	}
	int ma = 0;
	// for(auto it : se) {
	// 	if(it.second > ma)
	// 		cout << it.second << endl;
	// 	ma = max(ma,it.second);
	// }
	vector<int> v;
	int val = 9;
	for(int iter = 0;iter < 16;iter++) {
		for(i = 1;i <= 1000;i++) {
			// cout << i*(val+1) + val << endl;
			int val2 = i*(val+1) + val;
			int sum = 0;
			while(val2) {
				sum += val2%10;
				val2 /= 10;
			}
			double an = i*(val+1) + val;
			an /= sum;
			se.insert({an,i*(val+1) + val});
		}
		val *= 10;
		val += 9;
	}
	ma = 0;
	int cnt = 0;
	for(auto it : se) {
		if(cnt == n) break;
		if(it.second > ma) {
			cnt++;
			cout << it.second << endl;
		}
		ma = max(ma,it.second);
		// trace(ma);
	}
}