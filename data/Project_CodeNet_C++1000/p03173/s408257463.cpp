#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;
	cin >> n;
   	vector<int> A(n, 0);
   	vector < vector<ll> > cost(n, vector<ll> (n, 0));
   	vector < vector<ll> > siz(n, vector<ll> (n, 0));
   	for(int i = 0; i < n; i++){
		cin >> A[i];
		cost[i][i] = 0;
		siz[i][i] = A[i];
	}
   
   	ll mini;
   	for(int k = 1; k < n; k++){
		for(int i = 0; (i + k) < n; i++){
          	mini = -1;
			for(int j = i; j < i+k; j++){
				if(mini == -1){
					mini = cost[i][j] + siz[i][j] + cost[j+1][i+k] + siz[j+1][i+k];
					siz[i][i+k] = siz[i][j] +  siz[j+1][i+k];
				}
				if(mini > cost[i][j] + siz[i][j] + cost[j+1][i+k] + siz[j+1][i+k] ){
					mini = cost[i][j] + siz[i][j] + cost[j+1][i+k] + siz[j+1][i+k];
					siz[i][i+k] = siz[i][j] +  siz[j+1][i+k];
				}
 			}
			cost[i][i+k] = mini;
		}
	}	
	
   	cout << cost[0][n-1] << endl;

   	return 0;
   
}
