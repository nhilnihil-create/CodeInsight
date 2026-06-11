#include<bits/stdc++.h>
using namespace std;

bitset<16010> bx, by;
char s[100100];
int sx, sy;
vector<int> x, y;

int main(void) {
	scanf("%s%d%d", s, &sx, &sy);
	int n = strlen(s);
	int cnt = 0, p = 1;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'F') cnt++;
		else {
			(p ? x : y).push_back(cnt);
			p ^= 1;
			cnt = 0;
		}
	}
	(p ? x : y).push_back(cnt);	
	sx -= x[0];	
	if(sx < -8000) return puts("No") * 0;
	bx[8001] = 1;
	for(int i = 1; i < x.size(); i++) 
		bx = (bx << x[i]) | (bx >> x[i]);
	if(!bx[sx + 8001]) return puts("No") * 0;

	by[8001] = 1;
	for(int i = 0; i < y.size(); i++)
		by = (by << y[i]) | (by >> y[i]);
	if(!by[sy + 8001]) return puts("No") * 0;
	puts("Yes");
	return 0;
	
}