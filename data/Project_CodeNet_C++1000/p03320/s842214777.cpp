#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//typedef pair<int,int> P;


int sum(long long a){
	int ret = 0;
	while(a > 0){
		ret += a%10;
		a/=10;
	}
	return ret;
}

int main(){
	long long ans = 1;
	int k;
	scanf("%d",&k);

	for(int i=0;i<k;i++){
		printf("%lld\n",ans);
		long long best = -1;
        for(long long add = 1;add<=1000000000000000;add*=10){
			if(best==-1 || best*sum(ans+add)>(ans+add)*sum(best)){
				best=ans+add;
				//printf("best : %lld, add : %lld\n",best,add);
			}
		}
		ans = best;
	}

	return 0;
}
