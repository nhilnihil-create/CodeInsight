#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
	long long N;
	char S[200] = {0};
	char A[200] = {0};

	cin >> N;

	long long n = N;
	int i=0;
	while(true){
		if(n%2==0){
			S[i] = '0';
		}
		else{
			S[i] = '1';
			n = n -1;
		}
		n = n/(-2);
		if(n==0) break;
		i++;
	}

	int len = strlen(S);
	for(int i=0; i<len; i++){
		A[i] = S[len-1-i];
	}
	printf("%s\n", A);
	return 0;

}