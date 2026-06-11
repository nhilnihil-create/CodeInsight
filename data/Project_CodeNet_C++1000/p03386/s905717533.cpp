#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);

	int A,B,K; cin>>A>>B>>K;
	for(int i=A; i<=min(A+K-1, B); i++){
		cout << i << endl;
	}

	for(int i=max(B-K+1, A+K); i<=B; i++){
		cout << i << endl;
	}
}
