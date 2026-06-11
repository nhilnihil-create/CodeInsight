#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int count = 0;
	int N; cin >> N;
	vector<int> A(N);
	rep(i,N){
	cin >> A[i];
	if(A[i] % 2 == 0) count++;
	}

	cout << pow(3,N) - pow(2,count) << endl;
}