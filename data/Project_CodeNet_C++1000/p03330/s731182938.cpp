#include<bits/stdc++.h>


int main(){
	int n, c;
	scanf("%d %d", &n, &c);
	int d[c][c], grid[n][n], cc[3][c];
	memset(cc, 0, sizeof(cc));
	for(int i=0; i<c*c; i++) scanf("%d", &d[i/c][i%c]);
	for(int i=0; i<n; i++) for(int j=0; j<n; j++){
		scanf("%d", &grid[i][j]);
		grid[i][j]--;
		cc[(i+j)%3][grid[i][j]]++;
	}

	int ans = 1e11;	
	for(int i=0; i<c; i++){
		for(int j=0; j<c; j++) if(i!=j){
			for(int k=0; k<c; k++) if(i!=k && j!=k){
				int tmp = 0;
				for(int l=0; l<c; l++) tmp += cc[0][l] * d[l][i];
				for(int l=0; l<c; l++) tmp += cc[1][l] * d[l][j];
				for(int l=0; l<c; l++) tmp += cc[2][l] * d[l][k];
				ans = std::min(ans, tmp);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
