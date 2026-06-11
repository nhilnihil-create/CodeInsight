#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++) 
using namespace std;
typedef long long ll;

int main(){
	vector<int> v(3);
	rep(i,3) cin>>v[i];
	sort(v.begin(),v.end(),greater<int>());
	string a=to_string(v[0]) + to_string(v[1]);
	cout << stoi(a) + v[2] << endl;
}