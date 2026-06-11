#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;

int main(){
	string S;
	cin >> S;
	int N=S.size();
	int red=0, blue=0;
	rep(i,N){
		if(S[i]=='0') red++;
		else blue++;
	}
	cout << min(red,blue)*2 << endl;

	return 0;
}