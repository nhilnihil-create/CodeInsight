#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	ll n;
	cin >> n;
	vector<int> a(n+1);
	rep(j, n+1){
		int n0 = j;
		for(int i=2; i*i<=n0; i++){
			while(n0%i == 0 && n0/i != 1){
				a.at(i)++;
				n0 /= i;
			}
		}
		a.at(n0)++;
	}
	vector<int> n3(0);
	rep(i, n+1){
		if(a.at(i) >= 2){
			n3.push_back(a.at(i));
		}
	}
	ll ans = 0;
	rep(i, n3.size()){
		for(int j=0; j<n3.size()-1; j++){
			for(int l=j+1; l<n3.size(); l++){
				if(i == j || i == l) continue;
				if(n3.at(j) < 4 || n3.at(l) < 4) continue;
				ans++;
			}
		}
		if(n3.at(i) >= 24){
			for(int j=0; j<n3.size(); j++){
				if(i == j) continue;
				ans++;
			}
		}
		if(n3.at(i) >= 14){
			for(int j=0; j<n3.size(); j++){
				if(i == j) continue;
				if(n3.at(j) < 4) continue;
				ans++;
			}
		}
		if(n3.at(i) >= 74) ans++;
	}
	cout << ans << endl;
	return 0;
}
