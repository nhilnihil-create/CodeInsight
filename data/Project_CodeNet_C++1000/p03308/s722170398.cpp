#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> vec;
	int ans = -1e9;
	for(int i = 0; i < n; i++){
	 	int t; cin >> t; vec.pb(t);
	}
	for(int i = 0; i  < n; i++){
	 for(int j = i+1; j < n; j++){
	  	ans = max(ans, abs(vec[j]-vec[i]));
	 }
	}
	cout << ans << endl;
	return 0;
}                  
