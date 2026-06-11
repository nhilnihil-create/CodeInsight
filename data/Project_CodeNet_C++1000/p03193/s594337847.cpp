#include "bits/stdc++.h"
using namespace std;
int main(){
	int N, H, W;
	cin >> N >> H >> W;
	vector<int> A(N);
	vector<int> B(N);
	int sum = 0;
	for(int x= 0;x<N;x++){
		cin >> A[x];
		cin >> B[x];
		if(A[x]>=H && B[x]>=W){
			sum++;
		}
	}
	cout << sum;
	
}
