#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
	int N,K;
	cin >> N >> K;
	char* S = (char*)calloc(N+1, sizeof(char));
	cin >> S;
	
	for(int i = 0; i < N; i++){
		if(i+1 == K)
			S[i] += 32;
	}
	
	cout << S << endl;
	
}