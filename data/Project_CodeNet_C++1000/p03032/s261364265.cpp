#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];

	int lim = min(n,k);
	int ans = 0;
	for(int l=0; l<=lim; l++){
		for(int r=0; r<=lim-l; r++){
			int d = k-l-r;
			int point = 0;
			vector<int> s;

			for(int i=0; i<l; i++){
				s.push_back(v[i]);
				point += v[i];
			}
			for(int j=0; j<r; j++){
				s.push_back(v[n-1-j]);
				point += v[n-1-j];
			}

			sort(s.begin(),s.end());

			for(int i=0; i<d; i++){
				if(i >= s.size()) break;
				if(s[i] > 0) break;
				point -= s[i];
			}

			ans = max(ans,point);
		}
	}

	cout << ans << endl;
}