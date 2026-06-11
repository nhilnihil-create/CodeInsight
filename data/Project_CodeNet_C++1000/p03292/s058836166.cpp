#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n,x;
	n=3;
	vector<long long int> v;
	while(n--){
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	cout<<abs(v[1]-v[0])+abs(v[2]-v[1]);
	return 0;
}