#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int N, K;
	cin >> N >> K;
	
	double prob = 0.0;
	
	rep(i, N){
		int score = i+1;
		double chance = 1.0/(double)N;
		while(score < K){
			chance *= 0.5;
			score *= 2;
		}
		prob += chance;
	}
	
	printf("%.10f\n", prob);
	
}