#include <bits/stdc++.h>

using namespace std;

long long int n,i,j,k;
long long int kompatybilnosc[17][17];
long long int tablica[1<<17];
long long int dp[1<<17];

int main() {
	cin >> n;
	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> kompatybilnosc[i][j];
        }
	}
	for(i=1;i<1<<n;i++){
		for(j=0;j<n;j++){
			if(i>>j&1){
				tablica[i]=tablica[i^(1<<j)];
				for(k=0;k<n;k++){
                    if(i>>k&1){
                        tablica[i]+=kompatybilnosc[j][k];
                    }
				}
			}
		}
	}
	for(i=1;i<1<<n;i++){
		for(j=i;j!=0;j=(j-1)&i){
			dp[i]=max(dp[i],dp[i^j]+tablica[j]);
		}
	}
	cout<<dp[(1<<n)-1];
}
