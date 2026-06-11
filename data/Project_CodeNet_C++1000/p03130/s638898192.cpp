#include <bits/stdc++.h>



using namespace std;

#define MAXN 100


int adj[MAXN][MAXN];
int cam[MAXN];
int ok;

int solve(int ind){
	if(ind == 5){
		int i;
		//cout << "i: ";
		
		for(i = 1; i <= 3; i++){
			for(int j = 1; j <= 4; j++){
				if(cam[i] == cam[j] && i != j) return 0;
			}
			if(!adj[cam[i]][cam[i+1]]){
				return 0;
			}
			//cout << cam[i] << " ";
		}
		//cout << '!' << endl;
		ok = 1;
		return 1;
	}
	int i;
	for(i = 1; i <= 4; i++){
		cam[ind] = i;
		solve(ind+1);
	}
	return 666;
}



int main (){
	
	int n= 4;
	int u, v;
	
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	
	solve(1);
	
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}
