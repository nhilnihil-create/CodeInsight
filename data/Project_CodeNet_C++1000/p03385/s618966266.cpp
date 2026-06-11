#include <bits/stdc++.h>
using namespace std;

signed main(){
	vector<char> S(3);
	scanf("%c%c%c", &S[0], &S[1], &S[2]);
	sort(S.begin(), S.end());
	if(S[0] == 'a' && S[1] == 'b' && S[2] == 'c'){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}