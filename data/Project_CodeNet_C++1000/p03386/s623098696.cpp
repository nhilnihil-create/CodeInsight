#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	LL A, B;cin >> A >> B;
	LL K;cin >> K;
	LL m, M;
	m = min(A + K, B);
	M = max (B - K + 1, A);
	if(m>M) M = m;
	for(LL i = A;i < m ; i++){
		cout << i << endl;
	}

	for(LL i = M; i <= B; i++){
		cout << i << endl;
	}
	return 0;

}










