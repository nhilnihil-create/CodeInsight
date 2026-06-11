#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;

int main(){
	vector<int> vec;
	for(int i = 0; i < 3; i++){
	 	int t; cin >> t;
	 	vec.pb(t);
	}
	sort(vec.begin(), vec.end());
	int sum = 0;
	for(int i = 1; i < vec.size(); i++){
	 	sum += vec[i]-vec[i-1];
	}
	cout << sum << endl;
	return 0;
}                  
