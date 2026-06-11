#include <iostream>

using namespace std;

int dp[100000];

void stones(int* A,int N,int K){

	for(int i = 0;i <= K ;i++){
		
		if( i < A[0])
			dp[i] = 2;


		else{
			int m = 0;
			for(int j = 0; j < N && i >= A[j] ;j++){
				m = max(m,dp[i-A[j]]);
				if(m == 2){
					dp[i] = 1;
					break;
				}				
			}
			
			if(m == 1) dp[i] = 2;
		}

	}


}



int main(){

	int N,K;
	cin >> N >> K;

	int A[N];
	for(int i=0;i<N;i++){
		cin >> A[i];
	}

	stones(A,N,K);
	
	if (dp[K] == 1) cout << "First" <<'\n';
	else if (dp[K] == 2) cout << "Second" <<'\n';
	
	/*
	for(int i = 0;i <= K ;i++)
		cout << dp[i] << ' ';
	*/

	return 0;
}