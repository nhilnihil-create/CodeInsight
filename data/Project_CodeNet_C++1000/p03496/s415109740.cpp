#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


struct Info{
	Info(int arg_x,int arg_y){

		x = arg_x;
		y = arg_y;
	}
	int x,y;
};

int N;
ll table[51];
vector<Info> ANS;

int main(){

	scanf("%d",&N);

	ll minimum = BIG_NUM,maximum = -BIG_NUM;

	for(int i = 0; i < N; i++){

		scanf("%lld",&table[i]);

		minimum = min(minimum,table[i]);
		maximum = max(maximum,table[i]);
	}

	//printf("min:%lld maxi:%lld\n",minimum,maximum);

	if(minimum == maximum){

		printf("0\n");
		return 0;
	}

	ll base_num;

	if(abs(minimum) <= abs(maximum)){

		base_num = maximum;
	}else{

		base_num = minimum;
	}

	int base_index;
	for(int i = 0; i < N; i++){

		if(table[i] == base_num){

			base_index = i;
			break;
		}
	}

	//printf("base_num:%d base_index:%d\n",base_num,base_index);

	int count = 0;

	if(base_num > 0){ //絶対値が最大である数が正の場合

		//負の値があれば、0以上にする
		for(int i = 0; i < N; i++){
			if(i == base_index || table[i] >= 0)continue;

			table[i] += base_num;
			count++;
			ANS.push_back(Info(base_index+1,i+1));
		}

		for(int i = 0; i < N-1; i++){
			if(table[i] <= table[i+1])continue;

			table[i+1] += table[base_index]; //0以上の数に現時点の最大値を足すので、必ずtable[i] <= table[i+1]になる
			count++;
			ANS.push_back(Info(base_index+1,i+2));
			base_num = table[i+1]; //最大値更新
			base_index = i+1;
		}

	}else{ //絶対値が最大である数が負の場合

		//正の値があれば、0以下にする
		for(int i = 0; i < N; i++){
			if(i == base_index || table[i] < 0)continue;

			table[i] += base_num;
			count++;
			ANS.push_back(Info(base_index+1,i+1));
		}

		for(int i = N-1; i >= 1; i--){
			if(table[i-1] <= table[i])continue;

			table[i-1] += table[base_index]; //0以下の数に現時点の最小値を足すので、必ずtable[i-1] <= table[i]になる
			count++;
			ANS.push_back(Info(base_index+1,i));
			base_num = table[i-1]; //最小値更新
			base_index = i-1;
		}
	}

	printf("%d\n",count);

	for(int i = 0; i < count; i++){

		printf("%d %d\n",ANS[i].x,ANS[i].y);
	}

	return 0;
}
