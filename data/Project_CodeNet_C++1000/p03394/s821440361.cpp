#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n;
bool appear[30005];

const int LIM = 30000;

int main(){
	scanf("%d", &n);
	if(n == 3){
		printf("2 5 63\n");
		return 0;
	}
	
	appear[2] = appear[4] = true;
	appear[3] = appear[9] = true;
	n -= 4;
		
	for(int i = 8; i <= LIM && n > 1; i += 6){
		appear[i] = true;
		appear[i + 2] = true;
		n -= 2;
	}
	for(int i = 15; i <= LIM && n > 1; i += 12){
		appear[i] = true;
		appear[i + 6] = true;
		n -= 2;
	}
	for(int i = 6; i <= LIM && n > 0; i += 6){
		appear[i] = true;
		n--;
	}
	for(int i = 1; i <= LIM; i++){
		if(appear[i]){
			printf("%d ", i);
		}
	}
	puts("");
	return 0;
}