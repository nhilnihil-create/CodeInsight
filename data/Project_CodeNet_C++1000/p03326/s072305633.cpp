#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



struct Info{

	ll x,y,z;
};

struct Data{
	Data(int arg_index,ll arg_value){
		index = arg_index;
		value = arg_value;
	}
	bool operator<(const struct Data &arg) const{

		return value < arg.value;
	}
	int index;
	ll value;
};

int N,M;
Info info[1005];

int main(){

	scanf("%d %d",&N,&M);

	for(int i = 0; i < N; i++){

		scanf("%lld %lld %lld",&info[i].x,&info[i].y,&info[i].z);
	}

	ll ans = 0;

	vector<Data> V;

	for(int a = -1; a <= 1; a += 2){
		for(int b = -1; b <= 1; b += 2){
			for(int c = -1; c <= 1; c += 2){

				V.clear();
				for(int i = 0; i < N; i++){

					ll tmp = info[i].x*a+info[i].y*b+info[i].z*c;
					//if(tmp <= 0)continue;

					V.push_back(Data(i,tmp));
				}

				sort(V.rbegin(),V.rend());

				ll sum_x = 0,sum_y = 0,sum_z = 0;
				for(int i = 0; i < M; i++){
					if(i == M)break;

					sum_x += info[V[i].index].x;
					sum_y += info[V[i].index].y;
					sum_z += info[V[i].index].z;
				}

				ans = max(ans,abs(sum_x)+abs(sum_y)+abs(sum_z));
			}
		}
	}

	printf("%lld\n",ans);

	return 0;
}
