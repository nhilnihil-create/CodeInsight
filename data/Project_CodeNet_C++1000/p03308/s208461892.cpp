#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N; cin >> N;
	LL m = 10000000010, M = 0;
	for(int i = 0; i < N; ++i) {
		LL tmp; cin >> tmp;
		m = min(m, tmp);
		M = max(M, tmp);
	}
	cout << M - m << endl;
}








