#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 200005

char S[SIZE],T[SIZE];
int int_S[SIZE],int_T[SIZE];
int table_S[26],table_T[26];


int main(){

	scanf("%s",S);
	scanf("%s",T);

	for(int i = 0; i < 26; i++){

		table_S[i] = -1;
		table_T[i] = -1;
	}

	int index_S = 0;
	int len;
	for(len = 0; S[len] != '\0'; len++);

	for(int i = 0; i < len; i++){

		int ch = S[i]-'a';
		if(table_S[ch] == -1){

			table_S[ch] = index_S++;
		}
		int_S[i] = table_S[ch];
	}

	int index_T = 0;

	for(int i = 0; i < len; i++){

		int ch = T[i]-'a';
		if(table_T[ch] == -1){

			table_T[ch] = index_T++;
		}
		int_T[i] = table_T[ch];
	}


	for(int i = 0; i < len; i++){

		if(int_S[i] != int_T[i]){

			printf("No\n");
			return 0;
		}
	}

	printf("Yes\n");

	return 0;
}
