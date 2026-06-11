#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n;
int s[200005];

int stk[200005], level[200005], p;

void print_stack(){
	printf("STACK: \n");
	for(int i = 1; i <= p; i++){
		printf("  i = %d: %d %d\n", i, stk[i], level[i]);
	}
}
bool ok(int alp){
//	printf("alp = %d\n", alp);
	// can form the strings with alphabet size alp?
	p = 0;
	for(int i = 1; i <= n; i++){
		bool clear_stuff = false;
		while(p > 0 && s[i] < stk[p]){
			clear_stuff = true;
			p--;
		}
		// here s[i] >= stk[p]
		if(p > 0 && s[i] == stk[p]){
			// could be a chain reaction!
			level[p]++;
		}else{
			stk[++p] = s[i];
			if(clear_stuff){
				level[p] = 2;
			}else{
				level[p] = 1;
			}
		}
		
//		print_stack();
		
		if(level[p] <= alp){
			continue;
		}
		while(level[p] > alp){
			if(p > 1 && stk[p - 1] == stk[p] - 1){
				level[p - 1]++;
				p--;
			}else{
				stk[p]--;
				if(stk[p] == 0){
					return false;
				}
				level[p] = 2;
				break;
			}
		}
		// need to add this at the end...
		stk[++p] = s[i];
		level[p] = 1;
//		printf("AFTER..");
//		print_stack();
	}
	return true;
}

int main(){
	scanf("%d", &n);
	bool can_one = true;
	for(int i = 1; i <= n; i++){
		scanf("%d", &s[i]);
		if(i > 1 && s[i] <= s[i - 1]){
			can_one = false;
		}
	}
	if(can_one){
		printf("1\n");
		return 0;
	}
	int l = 1, r = n;
	while(r - l > 1){
		int m = (l + r) >> 1;
		if(ok(m)) r = m;
		else l = m;
	}
	printf("%d\n", r);
	return 0;
}