#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int dfs(vector<int> &l,vector<vector<int>> r, vector<int> a, int k){
	int m = 1e9;
	if(k==l.size()){
		int sum{};
		for(int i=0; i<3; i++){
			if(r.at(i).size()==0) return (int)1e9;
			sum += (r.at(i).size()-1)*10;
			int le{};
			for(auto j:r.at(i)) le += j;
			sum += abs(a.at(i)-le);
		}
		m = sum;
	}
	else {
		for(int i=0; i<3; i++){
			r.at(i).push_back(l.at(k));
			m = min(m,dfs(l,r,a,k+1));
			r.at(i).pop_back();
		}
		m = min(m,dfs(l,r,a,k+1));
	}
	return m;
}

int main(){
	int n; cin>>n;
	vector<int> a(3);
	for(int i=0; i<3; i++) cin>>a.at(i);
	vector<int> l(n);
	for(auto &i:l) cin>>i;
	vector<vector<int>> r(3);
	cout << dfs(l,r,a,0) << endl;
	
}