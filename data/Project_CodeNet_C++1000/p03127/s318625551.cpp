#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	int n; cin>>n;
	int a; cin>>a;
	for(int i=1; i<n; i++){
		int b; cin>>b;
		a = __gcd(a,b);
	}
	cout << a << endl;
}