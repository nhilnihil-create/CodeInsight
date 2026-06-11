#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S, T; cin >> S >> T;

	int l = S.size();
	int notmatch = 0;
	for(int i=l-1; i>=0; i--){
		notmatch = 0;
		for(int j=0; j<l; j++){
			int pos = i+j;
			if(pos >= l) pos -=l;
			if(S[pos] != T[j]){
				notmatch = 1;
				break;
			}
		}
		if(notmatch == 0){
			break;
		}
	}
	if(notmatch == 1){
		printf("No\n");
	}
	else{
		printf("Yes\n");
	}
	return 0;
}