#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int a, b;

int main(void){
	cin >> a >> b;
	int ans = 0;
	for(int i = a; i <= b; i++){
		string s1, s2;
		s1 = to_string(i);
		s2 = s1;
		reverse(s2.begin(), s2.end());
		if(s1 == s2) ans++;
	}
	cout << ans << endl;
	return 0;
}
