#include<bits/stdc++.h>

using namespace std;

int main(){

	int N,K;

	cin >> N>> K;

	vector<int> A(N,0);

	for(int i=0;i<N;i++){
		cin >> A[i];
	}

	vector<int> DP(K+1,0);

	for(int k=1;k<=K;k++){

		int s = 1;
		for(int j=0;j<N;j++){

			if(k>=A[j]){
				s = (s)&&(DP[k-A[j]]);
			}
		}

		DP[k] = (!s);
		
	}
	

	string ans = (DP[K]==1)?"First":"Second";
	cout << ans << endl;

	return 0;
}