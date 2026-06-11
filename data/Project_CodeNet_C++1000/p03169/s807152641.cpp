#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//State
//dp[a][b][c]: The expceted number of operations so to empty all plates when started with
// "a" number of 1 sushi plates, "b" number of 2 sushi plates, "c" number of 3 sushi plates

//Initialization
//dp[0][0][0] = 0

//Transitions
//dp[a][b][c] =  ((N-(a+b+c))/N)*dp[a][b][c] + (a/N)*dp[a-1][b][c] + (b/N)*dp[a+1][b-1][c] + (c/N)*dp[a][b+1][c-1] + 1
//dp[a][b][c] = N/(a+b+c) + (a/(a+b+c))*dp[a-1][b][c] + (b/(a+b+c))*dp[a+1][b-1][c] + (c/(a+b+c))*dp[a][b+1][c-1]

//Order of evaluation
//Outer Loop: c, Middle Loop: b, Inner Loop: a

//Answer: dp[n1][n2][n3]

//Time complexity: O(n1*n2*n3)

int main(){
    int N;
	cin >> N;
	int A[N+1];
	int ones = 0;
	int twos = 0;
	int threes = 0;
	
	for(int i=1; i<=N; i++){
		cin >> A[i];
		if(A[i] == 1) ones = ones+1;
		if(A[i] == 2) twos = twos+1;
		if(A[i] == 3) threes = threes+1;
	}
	
    //double dp[ones+twos+threes+1][twos+threes+1][threes+1] = {0};
    double dp[305][305][305] = {0};
    dp[0][0][0] = 0;
	for(int c=0; c<=threes; c++){
		for(int b=0; b<=twos+threes; b++){
			for(int a=0; a<= ones+twos+threes; a++){
				if(a!=0||b!=0||c!=0){
					dp[a][b][c] = (double) N/(a+b+c);
					if(a>0){
						dp[a][b][c] += (((double) a)/(a+b+c))*dp[a-1][b][c];
					}
					if(b>0){
						dp[a][b][c] += (((double) b)/(a+b+c))*dp[a+1][b-1][c];
					}
					if(c>0){
						dp[a][b][c] += (((double) c)/(a+b+c))*dp[a][b+1][c-1];
					}
				}
			}
		}
	}

	//cout << dp[ones][twos][threes] << endl;
	//printf("%0.10lf\n", dp[ones][twos][threes]);
	cout << fixed << setprecision(10) << dp[ones][twos][threes] << endl;

}