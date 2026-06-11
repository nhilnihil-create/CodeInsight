#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	string S, T;
	cin >> S >> T;
	int N = S.size();
	rep(i,N){
		string U;
		rep(j,N) U += S[(i+j)%N];
		if(U == T) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;



}








