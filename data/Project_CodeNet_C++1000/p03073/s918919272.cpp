#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string S;
	cin >> S;
	int N = S.size();
	int c1 = 0, c2 = 0;
	rep(i,N){
		if (i%2 == 0 && S[i] == '1') c1++;
		if (i%2 == 1 && S[i] == '0') c1++;
	}
	rep(i,N){
		if (i%2 == 0 && S[i] == '0') c2++;
		if (i%2 == 1 && S[i] == '1') c2++;
	}
	cout << min(c1,c2) << endl;

	return 0;
}
