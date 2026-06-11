#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	REP(i, N){
		cin >> A[i];
	}

	bool is_exiestsd_odd = false;
	int sum = 0;
	while(1){
		REP(i, N){
			if(A[i] % 2 != 0){
				is_exiestsd_odd = true;
				break;
			}
			A[i] = A[i] / 2;
		}
		if(is_exiestsd_odd)
			break;
		sum++;
	}
	cout << sum << endl;
}
