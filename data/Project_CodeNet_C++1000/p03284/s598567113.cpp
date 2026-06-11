#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
	int N, K;

	cin >> N >> K;
	
	int ans = 0;
	if(N%K==0){ ans = 0; }
	else{ ans = 1;}
	printf("%d\n", ans);
	return 0;
}