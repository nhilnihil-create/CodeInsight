/*alurquiza*/
//T: Permutation
#include <bits/stdc++.h>

using namespace::std;

typedef long long LL;

const int SIZE = 3e3 + 1,MOD = 1e9 + 7;

long long DP[SIZE][SIZE];

long long query(LL A[SIZE],int ini,int fin){
	return (A[fin] - A[ini - 1] + MOD) % MOD;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// freopen("milkvisits.in","r",stdin);
	// freopen("milkvisits.out","w",stdout);

	int N;
	cin >> N;

	string S;
	cin >> S;

	fill(DP[1] + 1,DP[1] + SIZE,1);

	for(int i = 2;i <= N;i++){
		for(int j = 1;j <= i;j++){
			if(S[i - 2] == '<'){
				DP[i][j] = query(DP[i - 1],j,N);
			}
			else{//S[i - 1] == '>'
				DP[i][j] = query(DP[i - 1],1,j - 1);
			}

			// cerr << i << ' ' << j << ' ' << DP[i][j] << '\n';
		}
		for(int j = 2;j <= N;j++)
			DP[i][j] = (DP[i][j] + DP[i][j - 1]) % MOD;
	}

	cout << query(DP[N],1,N) << '\n';

	return 0;
}

//g++ -std=c++11 -Wall DS.cpp -o main