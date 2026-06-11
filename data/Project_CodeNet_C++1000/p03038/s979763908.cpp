#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 100005

struct Info{
	bool operator<(const struct Info &arg) const{

		return C > arg.C;
	}
	ll B,C;
};

ll N,M;
ll A[SIZE];
Info info[SIZE];

int main(){

	scanf("%lld %lld",&N,&M);

	for(int i = 0; i < N; i++){

		scanf("%lld",&A[i]);
	}
	sort(A,A+N);

	for(int i = 0; i < M; i++){

		scanf("%lld %lld",&info[i].B,&info[i].C);
	}
	sort(info,info+M);

	bool FLG;
	int index = 0;

	for(int i = 0; i < M && index < N; i++){

		if(info[i].C <= A[index])break;

		for(int k = 0; k < info[i].B && index < N; k++){

			if(info[i].C > A[index]){

				A[index++] = info[i].C;

			}else{

				break;
			}
		}
	}

	ll ans = 0;
	for(int i = 0; i < N; i++){

		ans += A[i];
	}

	printf("%lld\n",ans);

	return 0;
}
