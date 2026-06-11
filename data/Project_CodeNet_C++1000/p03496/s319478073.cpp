#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

vector<pair<int, int > > vec;
void op1(int n){
	for(int i = 2; i <= n; i++){
		vec.push_back({i - 1, i});
	}
}

void op2(int n){
	for(int i = n; i >= 2; i--){
		vec.push_back({i, i - 1});
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n;
	cin>>n;
	vector<int> a(n);
	int mn = 0, mx = 0;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	if(mx == 0){
		op2(n);
	}else if(mn == 0){
		op1(n);
	}else if(mx + mn >= 0){
		int ind;
		for(int i = 0; i < n; i++){
			if(a[i] == mx)ind = i;
		}
		for(int i = 0; i < n; i++){
			if(i == ind)continue;
			vec.push_back({ind + 1, i + 1});
		}
		op1(n);
	}else{
		int ind;
		for(int i = 0; i < n; i++){
			if(a[i] == mn)ind = i;
		}
		for(int i = 0; i < n; i++){
			if(i == ind)continue;
			vec.push_back({ind + 1, i + 1});
		}
		op2(n);
	}
	cout<<vec.size()<<'\n';
	for(auto x : vec){
		cout<<x.first<<" "<<x.second<<'\n';
	}

	return 0;
}