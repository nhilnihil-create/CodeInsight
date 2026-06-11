#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

long long ans = 0;
int consec, state, n;
char str[200005];

int main(){
	scanf("%s", str + 1);
	n = strlen(str + 1);
	state = 'a';
	for(int i = n; i > 0; i--){
		str[i] += ('a' - 'A'); // sorry I trolled
		if(str[i] == 'a'){
			if(state != 'b'){
				state = 'a';
				consec = 0;
			}else{
				ans += consec;
			}
		}else if(str[i] == 'b'){
			if(state == 'c'){
				consec++;
			}else{
				consec = 0;
			}
			state = 'b';
		}else{
			if(state != 'b'){
				consec = 0;
			}
			state = 'c';
		}
	}
	printf("%lld\n", ans);
	return 0;
}