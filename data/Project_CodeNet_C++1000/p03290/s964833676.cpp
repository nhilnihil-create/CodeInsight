#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 12

struct Info{

	ll P,C;
};

ll D,G;
int POW[SIZE];
Info info[SIZE];

int main(){

	POW[0] = 1;
	for(int i = 1; i < SIZE; i++){

		POW[i] = POW[i-1]*2;
	}

	scanf("%lld %lld",&D,&G);

	for(ll i = 0; i < D; i++){

		scanf("%lld %lld",&info[i].P,&info[i].C);
	}

	ll ans = BIG_NUM;

	for(int state = 0; state < POW[D]; state++){
		ll sum = 0;
		ll num = 0;

		//まずはコンプリートする問題を計上
		for(int loop = 0; loop < D; loop++){
			if(state&POW[loop]){
				sum += 100*(loop+1)*info[loop].P;
				sum += info[loop].C;
				num += info[loop].P;
			}
		}

		if(sum >= G){

			ans = min(ans,num);
			continue;
		}

		for(int loop = D; loop >= 0; loop--){ //得点の大きいものからやる
			if(state&POW[loop])continue;

			for(int i = 1; i <= info[loop].P-1; i++){ //コンプリートはしない
				sum += 100*(loop+1);
				num++;
				if(sum >= G)break;
			}
			if(sum >= G)break;
		}
		if(sum >= G){

			ans = min(ans,num);
		}
	}

	printf("%lld\n",ans);

	return 0;
}
