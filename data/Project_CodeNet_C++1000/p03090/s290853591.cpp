#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>
#include <climits>
#include <set>
#include <list>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
	int N;
	cin >> N;
	int M;
	if(N == 3){
		M = 2;
	}else if(N % 2 == 0){
		M = N*(N-2)/2;
	}else{
		M = (N-1)*(N-3)/2 + (N-1);
	}
	cout << M << endl;
	
	if(N == 3){
		cout << "1 3" << endl;
		cout << "2 3" << endl;
		return 0;
	}
	
	if(N % 2 == 0){
		for(int i = 1; i <= N; i++){
			for(int j = i+1; j <= N; j++){
				if(i+j != N+1){
					cout << i << " " << j << endl;
				}
			}
		}
	}else{
		for(int i = 1; i <= N; i++){
			for(int j = i+1; j <= N; j++){
				if(i == N || j == N){
					cout << i << " " << j << endl;
				}
				else if(i+j != N){
					cout << i << " " << j << endl;
				}
			}
		}
	}
	
	return 0;
}