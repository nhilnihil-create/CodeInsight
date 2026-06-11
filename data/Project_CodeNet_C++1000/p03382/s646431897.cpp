#include<bits/stdc++.h>
using namespace std;

long long N;
vector<long long> A;
int main(){
	cin >> N;
	for(long long i = 0; i < N; i++){
		long long tmp;
		cin >> tmp;
		A.push_back(tmp);
	}

	sort(A.begin(), A.end());
	long long maxi = A[A.size() - 1];
	long long midi = A[0];

	for(long long i = 0; i < N-1; i++){
		if(abs((double)midi - (double)maxi/2.0) > abs((double)A[i] - (double)maxi/2.0))
			midi = A[i];
	}
	cout << maxi << " " << midi << endl;
}
