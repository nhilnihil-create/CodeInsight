#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


enum Type{
	Query,
	Range,
};

struct Info{
	Info(int arg_left,int arg_right,Type arg_type,int arg_index){
		left = arg_left,
		right = arg_right;
		type = arg_type;
		index = arg_index;
	}
	bool operator<(const struct Info &arg) const{

		if(left != arg.left){

			return left < arg.left;
		}else{

			return type < arg.type; //クエリの方が左に来るようにする
		}
	}

	Type type;
	int left,right,index;
};

int N,M,num_query;
ll BIT[505];
ll ans[100005];
vector<Info> info;

void add(int loc,ll value){

	BIT[loc] += value;

	loc += loc & -loc; //最後の1ビットを足した場所が次の★更新★場所

	while(loc <= N){
		BIT[loc] += value;
		loc += loc & -loc;
	}
}

ll getSum(int loc){

	ll sum = BIT[loc];

	loc -= loc & -loc; //最後の1ビットを引いた場所が次の★加算★場所

	while(loc > 0){
		sum += BIT[loc];
		loc -= loc & -loc;
	}
	return sum;
}

ll calc(int left,int right){ //left～rightの区間の総和を、sum(1～right)-sum(1～left-1)で求める
	return getSum(right)-getSum(left-1);
}

int main(){

	scanf("%d %d %d",&N,&M,&num_query);

	for(int i = 0; i <= N; i++){

		BIT[i] = 0;
	}

	int left,right;
	for(int i = 0; i < M; i++){

		scanf("%d %d",&left,&right);
		info.push_back(Info(left,right,Range,i));
	}

	for(int i = 0; i < num_query; i++){

		scanf("%d %d",&left,&right);
		info.push_back(Info(left,right,Query,i));
	}
	sort(info.begin(),info.end());

	for(int i = info.size()-1; i >= 0; i--){

		if(info[i].type == Range){

			add(info[i].right,1);

		}else{ //info[i].type == Query

			ans[info[i].index] = getSum(info[i].right);
		}
	}

	for(int i = 0; i < num_query; i++){

		printf("%lld\n",ans[i]);
	}

	return 0;
}
