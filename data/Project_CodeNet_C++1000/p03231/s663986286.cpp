#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n , m;
string s , t;
ll fpb(ll a , ll b){
	if(a == 0)return b;
	return fpb(b % a , a);
}
ll kpk(ll a , ll b){
	return a/fpb(a,b) * b;
}
bool valid(string s , string t){
	ll f = fpb(n , m);
	for(int i = 0 ; i < f ; i++){
		if(s[i*n/f] != t[i*m/f])return false;	
	}
	return true;
}
int main(){
	cin >> n >> m;
	cin >> s >> t;
	if(valid(s, t))cout << kpk(n , m) << endl;
	else cout << -1 << endl; 
}