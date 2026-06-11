#include<iostream>
#include<map>
#include<vector>

using namespace std;

vector<long long> sum(int n, vector<long long>a){
	vector<long long> s(n);
	for(int i = 0;i<n;i++){
		if(i == 0){
			s[i] = a[i];
			continue;
		}
		s[i] = s[i-1] + a[i];
	}
	return s;
}

int main(){
	long long m, n, ans = 0,r;
	cin >> n >> m;
	vector<long long> a(n); 
	for(int i = 0; i<n; i++) cin >> a[i];
	map<int, int> map;
	map[0] = 1;
	vector<long long> s = sum(n,a); 
	for(int i = 0; i<n; i++){
		r = s[i]%m;
		ans += map[r];
		map[r]++;
	}
	cout << ans;
}