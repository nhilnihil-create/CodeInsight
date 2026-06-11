#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 200005

ll N;
int A[SIZE];
int max_digit = 19;
int POW[20],table[SIZE][20],work[20];

bool isOK(){

	for(int i = 0; i <= max_digit; i++){

		if(work[i] >= 2)return false;
	}
	return true;
}


int main(){

	scanf("%lld",&N);

	for(ll i = 1; i <= N; i++){

		scanf("%d",&A[i]);
	}

	POW[0] = 1;
	for(int i = 1; i <= max_digit; i++){

		POW[i] = POW[i-1]*2;
	}


	for(int k = 0; k <= max_digit; k++){

		table[0][k] = 0;
	}

	for(ll i = 1; i <= N; i++){

		for(int k = 0; k <= max_digit; k++){

			table[i][k] = table[i-1][k];
			if(A[i]&POW[k]){

				table[i][k]++;
			}
		}
	}

	ll ans = 0;

	ll left,right,mid,R;

	for(ll L = 1; L <= N; L++){

		left = L,right=N,mid=(left+right)/2;
		R = -1;

		while(left <= right){

			for(int i = 0; i <= max_digit; i++){

				work[i] = table[mid][i]-table[L-1][i];
			}

			if(isOK()){

				R = mid;
				left = mid+1;
			}else{

				right = mid-1;
			}
			mid = (left+right)/2;
		}

		if(R == -1)continue;

		ans += (R-L+1);
	}

	printf("%lld\n",ans);

	return 0;
}
