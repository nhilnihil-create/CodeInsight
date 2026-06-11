#include<bits/stdc++.h>
using namespace std;

long long anum, bnum, cnum;

int main(){
	string S;
	cin >> S;
	for(long long i = 0; i < S.size(); i++){
		if(S[i] == 'a'){
			anum++;
		}else if(S[i] == 'b'){
			bnum++;
		}else{
			cnum++;
		}
	}

	if(max(anum, max(bnum, cnum)) - min(anum, min(bnum, cnum)) >= 2){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
	}

}