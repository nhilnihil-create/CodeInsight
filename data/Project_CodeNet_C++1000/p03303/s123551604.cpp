#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
string s, ans;
int n;
int main(){
	cin >> s >> n;
	rep(i,s.size()) if(i%n==0) ans.push_back(s[i]);
	cout << ans << "\n";
}