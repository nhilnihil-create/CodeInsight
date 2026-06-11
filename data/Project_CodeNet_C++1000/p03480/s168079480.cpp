#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	string s;
	cin >> s;
	int n=s.length();

	int ans=n;
	for(int i=1; i<n; i++){
		if(s[i]!=s[i-1]){
			ans=min(ans, max(i, n-i));
		}
	}
	cout << ans << endl;
	return 0;
}