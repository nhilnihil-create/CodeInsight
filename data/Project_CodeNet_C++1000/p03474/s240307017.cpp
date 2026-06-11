#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int A, B;cin >> A >> B;
	string S;
	cin >> S;
	bool ok = true;
	rep(i,A){
		if(!(S[i] >= '0')) ok = false;
	}
	if(S[A] != '-') ok = false;

	rep(i,B-1){
		if(!(S[A+1+i] >= '0')) ok = false;
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;

		
}










