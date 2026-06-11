#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int len;
char str[29];
bool app[128];

int main(){
	scanf("%s", str);
	len = strlen(str);
	if(len == 26){
		for(int i = 25; i > 0; i--){
			if(str[i - 1] < str[i]){
				// choose next largest for str[i - 1]
				// sort the rest
				int select = -1;
				for(int j = i; j < 26; j++){
					if(str[j] > str[i - 1]){
						if(select == -1 || str[j] < str[select]){
							select = j;
						}
					}
				}
				swap(str[i - 1], str[select]);
				str[i] = 0;
				puts(str);
				return 0;
			}
		}
		printf("-1\n");
	}
	else{
		for(int i = 0; i < len; i++){
			app[str[i]] = true;
		}
		for(int i = 'a'; i <= 'z'; i++){
			if(!app[i]){
				printf("%s%c\n", str, i);
				return 0;
			}
		}
	}
}