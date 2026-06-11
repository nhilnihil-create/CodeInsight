#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int N;
string line[105];

int main(){

	scanf("%d",&N);

	bool FLG = true;

	for(int i = 0; i < N; i++){

		cin >> line[i];
		if(i == 0 || !FLG)continue;

		if(line[i-1][line[i-1].length()-1] != line[i][0]){

			FLG = false;
			continue;
		}
		for(int k = 0; k < i; k++){

			if(line[k] == line[i]){

				FLG =false;
				break;
			}
		}
	}

	if(FLG){

		printf("Yes\n");
	}else{

		printf("No\n");
	}


	return 0;
}
