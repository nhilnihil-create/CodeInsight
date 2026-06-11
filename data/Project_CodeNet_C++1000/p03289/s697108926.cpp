#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	string S;cin >> S;
	bool ok = true;
	if(S[0] == 'A') S[0] = 'a';
	else ok = false;
	int tmp = 0;
	for(int i = 2; i < S.size() - 1; i++){
		if(S[i]=='C'){
			S[i] = 'c';
			tmp++;
		}
	}
	if(tmp!=1) ok = false;
	rep(i,S.size()){
		if(S[i] >= 'A' && S[i] <= 'Z') ok = false;
	}
	if(ok) cout << "AC" << endl;
	else cout << "WA" << endl;
	return 0;



}








