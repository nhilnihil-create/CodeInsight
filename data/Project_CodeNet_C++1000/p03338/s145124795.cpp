#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
    string S;
    cin >> N >> S;
	int ans = 0;
	for(int i = 1; i < N; i++){
		int X[26] = {};
        int Y[26] = {};
        int cnt = 0;
		for(int j = 0; j < i; j++){
			X[S[j]-'a'] = 1;
		}
		for(int j = i; j < N; j++){
			Y[S[j]-'a'] = 1;
		}
		for(int j = 0; j < 26; j++){
	        if(X[j] == Y[j] && X[j] == 1) {
                cnt++;
            }
		}
        ans = max(ans,cnt);
	}
	cout << ans << endl;
}	