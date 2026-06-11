#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){

	int N, K;
	string S;
	cin >> N >> K;
	cin >> S;
	for(int i=0; i<S.size(); i++){
		if(i == K-1){
			if(S[i] == 'A'){ S[i] = 'a'; }
			else if(S[i] == 'B'){ S[i] = 'b'; }
			else if(S[i] == 'C'){ S[i] = 'c'; }
		}
	}
	printf("%s\n", S.c_str());
	return 0;
}
