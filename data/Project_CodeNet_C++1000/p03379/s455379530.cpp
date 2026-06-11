#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

typedef long long ll;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;
	vector<P> X(n);
	P a;
	int mid = n/2;
	rep(i,n){int t; cin >> t; X[i] = make_pair(t,i+1); }
	sort(X.begin(),X.end());

	vector<int> ans(n);
	rep(i,n){
		swap(X[0],X[i]);
		int idx = X[0].second;
		ans[idx-1] = X[mid].first;
	}

	for(int u : ans){
		cout << u << endl;
	}

	return 0;
}