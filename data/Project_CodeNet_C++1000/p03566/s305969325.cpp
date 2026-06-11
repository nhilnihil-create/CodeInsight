#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 105

struct Info{

	double limit,t;
};

struct Data{
	void set(int arg_left,int arg_right,int arg_limit){
		left = arg_left;
		right = arg_right;
		limit = arg_limit;
	}
	double left,right,limit;
};

int N;
double from_L[NUM],from_R[NUM],ans[NUM];
Info info[NUM];
Data data[NUM];

int main(){

	scanf("%d",&N);

	info[0].t = 0;
	for(int i = 1; i <= N; i++){

		scanf("%lf",&info[i].t);
		info[i].t += info[i-1].t;
	}
	info[N+1].t = info[N].t;


	info[0].limit = 0;
	for(int i = 1; i <= N; i++){

		scanf("%lf",&info[i].limit);
	}
	info[N+1].limit = 0;

	data[0].set(0,0,0);
	for(int i = 1; i <= N; i++){

		data[i].set(info[i-1].t,info[i].t,info[i].limit);
	}
	data[N+1].set(info[N].t,info[N].t,0);


	double ans = 0,pre = 0,minimum;
	int index;

	//1秒ごとに求める
	for(double current = 0; current < info[N+1].t || fabs(info[N+1].t-current) < EPS; current += 0.5){

		//printf("current]%.1lf\n",current);

		minimum = BIG_NUM;

		for(index = 0; current-data[index].right >= EPS; index++){ //左側

			minimum = min(minimum,data[index].limit+(current-data[index].right)*1);
		}
		minimum = min(minimum,data[index].limit); //currentをleft-rightに含む区間

		for(++index; index <= N+1; index++){

			minimum = min(minimum,data[index].limit+(data[index].left-current)*1); //右側
		}

		ans += (pre+minimum); //台形の面積

		pre = minimum;
	}

	printf("%.10lf\n",ans/4);

	return 0;
}
