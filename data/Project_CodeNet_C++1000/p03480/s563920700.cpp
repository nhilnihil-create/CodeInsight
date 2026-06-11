#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	string s;
	cin >> s;
	int ans = s.length();
	for (int i = 0; i < s.length()-1; i++){
		if (s[i] != s[i+1]){
			int temp = max(i+1, (int)s.length()-i-1);
			ans = min(temp, ans);
		}
	}
	cout << ans << endl;
	return 0;
}
