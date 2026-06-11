#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++) 
using namespace std;
typedef long long ll;

int main(){
	vector<int> v(3);
	rep(i,3) cin>>v[i];
	sort(v.begin(), v.end());
	cout << abs(v[1]-v[0]+v[2]-v[1]) << endl;	
}