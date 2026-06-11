#include <bits/stdc++.h>

using namespace std;

char S[8080];
vector <int> X, Y;
bool D[8080];
int x, y;

void die() { printf("No\n"); exit(0); }

int main()
{
	int i, d, s;
	
	scanf("%s%d%d", S, &x, &y);
	
	for(i=0; S[i] && S[i] != 'T'; i++);
	x -= i;
	
	if(!S[i] && (x || y)) die();
	
	x = abs(x); y = abs(y);
	
	for(d=1, s=0; S[i]; i++){
		if(S[i] == 'F') s ++; 
		else{
			if(s){
				(d? X : Y).push_back(s);
				(d? x : y) += s;
			}
			d = !d; s = 0;
		}	
	}
	
	if(s){
		(d? X : Y).push_back(s);
		(d? x : y) += s;
	}
	
	if((x & 1) || (y & 1)) die();
	x /= 2; y /= 2;
	
	D[0] = 1;
	
	for(int &t: X){
		for(i=x; i>=t; i--){
			D[i] |= D[i - t];
		}
	}
	
	if(!D[x]) die();
	
	for(i=1; i<=y; i++){
		D[i] = 0;
	}
	
	for(int &t: Y){
		for(i=y; i>=t; i--){
			D[i] |= D[i - t];
		}
	}
	
	if(!D[y]) die();
	
	printf("Yes\n");
	
	return 0;
}