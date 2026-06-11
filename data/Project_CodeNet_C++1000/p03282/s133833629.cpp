#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	string S;
	cin >> S;
	LL K;
	cin >> K;
	if(S.size() == 1){
		cout << S[0] << endl;
		return 0;
	}
	else {
		int tmp = 0;
		rep(i,S.size()){
			if(S[i]-'0' != 1) break;
			tmp++;
		}
		if(K<=tmp) {
			cout << 1 << endl;
			return 0;
		}
		else {
			cout << S[tmp] << endl;
			return 0;
		}
	}
	


}












