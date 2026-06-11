#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
	int N;
	cin >> N;

	int sum=0;
	int ans = 0;
	for(int x=0; 4*x<=N; x++){
		for(int y=0; 7*y<=N; y++){
			sum = 4*x + 7*y;
			if(sum==N){
				ans++;
				break;
			}
		}
		if(ans>0) break;
	}
	if(ans){printf("Yes\n");}
	else{printf("No\n");}
	return 0;
}