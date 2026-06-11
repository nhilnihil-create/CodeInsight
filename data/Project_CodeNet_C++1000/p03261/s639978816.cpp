#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
	int n;
	cin >> n;
	vector<string> w(n);
	rep(i,n) cin >> w[i];
	for(int i = 0;i < n-1;i++){
		for(int j = i+1;j < n;j++){
			if(w[i] == w[j]){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	rep(i,n-1){
		int ilen = w[i].size()-1;
		if(w[i][ilen] != w[i+1][0]){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}