#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int H, W, N, sr, sc;
char S[MAXN], T[MAXN];

bool calc(int s, int m){
	int L = 1, R = m;
	for(int i = N - 1; i >= 0; i--){
		if(S[i] == 'L' || S[i] == 'R'){
			if(T[i] == 'U'){
				R = min(m, R + 1);
			}else if(T[i] == 'D'){
				L = max(1, L - 1);
			}
		}else if(S[i] == 'U'){
			if(T[i] == 'D'){
				L = max(2, L);
			}else if(T[i] == 'U'){
				R = min(m, R + 1);
				L = L + 1;
			}else{
				L = L + 1;
			}
		}else{
			if(T[i] == 'U'){
				R = min(m - 1, R);
			}else if(T[i] == 'D'){
				L = max(1, L - 1);
				R = R - 1;
			}else{
				R = R - 1;
			}
		}
		
		if(L > R)return false;
	}
	if(s < L || s > R)return false;
	return true;
}
int main(){
	scanf("%d %d %d %d %d %s %s", &H, &W, &N, &sr, &sc, S, T);
	
	bool f1 = calc(sr, H);
	
	for(int i = 0; i < N; i++){
		if(S[i] == 'L')S[i] = 'U';
		else if(S[i] == 'R')S[i] = 'D';
		else if(S[i] == 'U')S[i] = 'L';
		else S[i] = 'R';
		
		if(T[i] == 'L')T[i] = 'U';
		else if(T[i] == 'R')T[i] = 'D';
		else if(T[i] == 'U')T[i] = 'L';
		else T[i] = 'R';
	}
	
	bool f2 = calc(sc, W);
	
	if(f1 && f2)printf("YES\n");
	else printf("NO\n");
	
	return 0;
}
