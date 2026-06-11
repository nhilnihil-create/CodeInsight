#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	string S;
	cin >> S;
	vector<int> A(4);
	for(int i = 0; i < 4; ++i){
		A[i] = S[i] - '0';
	}
	for (int bit = 0; bit < (1<<3); ++bit) {
		int tmp = A[0];
		vector<char> op(3);
		for (int i = 0; i < 3; ++i) {
			if(bit & (1<<i)) {
				tmp += A[i+1];
				op[i] = '+';
			}
			else {
				tmp -= A[i+1];
				op[i] = '-';
			}
		}
		if(tmp == 7){
			cout << A[0] << op[0] << A[1] << op[1] << A[2] << op[2] << A[3] << "=7" << endl;
			return 0;
		}
	}
	return 0;

}












