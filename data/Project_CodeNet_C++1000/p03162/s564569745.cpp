#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//dp[i][j]: The maximum happiness that Taro gains 
//	in the first i days if he choses activity Aj on i-th day

//Initialization
//dp[1][0] = a1, dp[1][1]=a2, dp[1][2]=a3

//Transitions: Two choices Choices: (Choose Ai, Aj different from the last choice)
//dp[i] = dp[i-1]

//Order of Evaluation
//Row wise: Outer Loop should be the i loop or days loop

//Answer
//max(dp[N][0], dp[N][1], dp[N][2])

//Time Complexity
// O(N)

int dp[100005][3] = {0};
int A[100005];
int B[100005];
int C[100005];

const int INF = 1e9+5;

int main(){
	int N;
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> A[i] >> B[i] >> C[i];
	}

	for(int j=0; j<=2; j++){
		dp[1][0] = A[1];
		dp[1][1] = B[1];
		dp[1][2] = C[1];
	}

	for(int i=2; i<=N; i++){
		for(int j=0; j<=2; j++){
			for(int k=0; k<=2; k++){
				if(j!=k){
					if(j==0) dp[i][j] = max(dp[i][j], dp[i-1][k]+A[i]);
					if(j==1) dp[i][j] = max(dp[i][j], dp[i-1][k]+B[i]);
					if(j==2) dp[i][j] = max(dp[i][j], dp[i-1][k]+C[i]);
				}
			}
		}
	}

	int result =0;
	for(int j=0; j<=2; j++){
		result = max(result, dp[N][j]);
	}
	cout << result << endl;
}