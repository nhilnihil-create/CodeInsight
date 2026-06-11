#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



char buf[105];
int table[2][26];

int main(){

	int len;
	scanf("%d",&len);
	scanf("%s",buf);

	int ans = 0;

	for(int right = 0; right <= len-2; right++){
		for(int i = 0; i < 2; i++){
			for(int k = 0; k < 26; k++){

				table[i][k] = 0;
			}
		}

		for(int i = 0; i <= right; i++){

			table[0][buf[i]-'a']++;
		}
		for(int i = right+1; i <= len-1; i++){

			table[1][buf[i]-'a']++;
		}
		int tmp = 0;
		for(int i = 0; i < 26; i++){

			if(table[0][i] > 0 && table[1][i] > 0){

				tmp++;
			}
		}
		ans = max(ans,tmp);
	}

	printf("%d\n",ans);

	return 0;
}
