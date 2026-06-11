#include <bits/stdc++.h>

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
using ll = long long;

int main(){
	fastIO;
	int n;
	double ans=0;
	cin >> n;
	vector<pair<string,string>> v(n);
	for(int i=0;i<n;++i){
		cin >> v[i].first >> v[i].second;
	}
	for(int i=0;i<n;++i){
		if(v[i].second == "JPY")
			ans+=stoi(v[i].first);
		else{
			ans+=stod(v[i].first)*380000.0;
		}
	}
	//cout.precision(4);
	cout << ans << '\n';
	return 0;
}