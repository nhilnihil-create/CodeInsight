#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	int n,k,q;
	cin >> n >> k >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int ans= 1e9;
	for(int i = 0; i < n; i++){
		//cout << a[i] << endl;
		vector<vector<int> > b;
		vector<int> res;
		for(int j = 0; j < n; j++){
			if(a[j]>=a[i]){
				res.push_back(a[j]);
				if(j==n-1){
					b.push_back(res);
					res.clear();
				}
			}else{
				b.push_back(res);
				res.clear();
			}
		}
		//cout << a[i] << endl;
		for(int j = 0; j < b.size(); j++){
			sort(all(b[j]));
			// cout << b[j].size() << endl;
			// for(int l = 0; l < b[j].size(); l++){
			// 	cout << b[j][l] << endl;
			// }
			if(b[j].size()<k) continue;
			for(int l = 0; l < b[j].size()-k+1; l++){
				res.push_back(b[j][l]);
			}
		}
		if(!res.empty()){
			sort(all(res));
			// for(int j = 0; j < res.size(); j++){
			// 	cout << res[j] << " ";
			// }printf("\n");
			if(res.size()>=q){
				ans = min(ans,res[q-1]-a[i]);
			}
		}
	}

	cout << ans << endl;

	return 0;
}