#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<int> V;
vector<int> C;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i=0; i<N; i++){
		long long v;
		cin >> v;
		V.push_back(v);
	}
	for(int i=0; i<N; i++){
		long long c;
		cin >> c;
		C.push_back(c);
	}

	int ans = 0;
	for(int b=0; b < (1<<N); b++){
		int X = 0, Y = 0;
		for(int i=0; i < N; i++){
			if(b & (1<<i)){
				X += V[i];
				Y += C[i];
			}
		}
		if(ans < (X - Y)){
			ans = X - Y;
		}
	}
	printf("%d\n", ans);
	return 0;
}