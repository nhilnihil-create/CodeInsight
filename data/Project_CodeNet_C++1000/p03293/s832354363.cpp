#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;




int main(){

	char S[105],T[105];

	scanf("%s %s",S,T);

	int len;
	for(len = 0; S[len] != '\0'; len++);

	for(int head = 0; head <= len-1; head++){
		bool FLG = true;
		for(int k = 0; k < len; k++){
			if(S[(head+k)%len] != T[k]){
				FLG = false;
				break;
			}
		}

		if(FLG){

			printf("Yes\n");
			return 0;
		}
	}

	printf("No\n");

	return 0;
}
