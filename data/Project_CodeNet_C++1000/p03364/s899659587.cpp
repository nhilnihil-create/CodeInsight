#include"bits/stdc++.h"
using namespace std;
#define LL long long
#define PB push_back
#define MP make_pair

int main(){
	int N;
	string S[300];
	cin >> N;
	for(int i=0; i<N; i++) cin >> S[i];
	int ans = 0;
	for(int i=0; i<N; i++){
		bool flg = true;
		for(int j=0; j<N; j++){
			for(int k=0; k<N; k++){
				if(S[j][k] != S[k][j]) flg = false;
			}
		}
		ans += flg * N;
		string s = S[0];
		for(int j=0; j<N-1; j++){
			S[j] = S[j+1];
		}
		S[N-1] = s;
	}
	cout << ans << endl;
}