#include <bits/stdc++.h>
using namespace std;

signed main(){
	string S;
	cin >> S;
	int ans = 0;
	for(int i = 0; i < 4; i++){
		if(S[i] == '+'){
			ans++;
		}
		else{
			ans--;
		}
	}
	printf("%d\n", ans);
	return 0;
}