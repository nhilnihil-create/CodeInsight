#include <cstdio>
#include <cstring>
#include <algorithm>

int n;
int w[233333];

int q[233333][2], t;
bool check(int a, int i = 1, int ls = 0){
	q[t = 1][0] = 0, q[t][1] = 0;
	q[++t][0] = 1, q[t][1] = 1;
	(w[1] == 1) && (i++);
	for(i; i <= n; i++){
		if(q[1][1]) return false;
		ls = w[i];
		if(q[t][0] < ls) q[++t][0] = ls, q[t][1] = 1;
		else{
			while(t){
				if(q[t][0] == ls){
					if(q[t][1] < a) {q[t][1]++; break;}
					else t--, ls--;
				}
				else if(q[t][0] < ls){
					q[++t][0] = ls, q[t][1] = 2;
					if(a == 1) return false;
					break;
				}
				else t--;
			}
			if(q[t][0] != w[i]) q[++t][0] = w[i], q[t][1] = 1;
		}
	}
	if(q[1][1]) return false;
	return true;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
	int l = 1, r = n, mid;
	while(l < r){
		mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	return !printf("%d\n", r);
}