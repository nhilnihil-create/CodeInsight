#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



char buf[4];
int table[26];


int main(){

	for(int i = 0; i < 26; i++){

		table[i] = 0;
	}

	scanf("%s",buf);

	for(int i = 0; i < 3; i++){

		table[buf[i]-'a']++;
	}

	if(table[0] == 1 && table[1] == 1 && table[2] == 1){

		printf("Yes\n");

	}else{

		printf("No\n");
	}

	return 0;
}
