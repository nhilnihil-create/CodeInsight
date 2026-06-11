#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 200005

struct Info{
	Info(int arg_value,int arg_loc){
		value = arg_value;
		loc = arg_loc;
	}
	bool operator<(const struct Info &arg) const{

		return value < arg.value;
	}

	int value,loc;
};

int N;
int table[SIZE];

int main(){

	scanf("%d",&N);

	vector<Info> V;
	int tmp;

	for(int i = 0; i < N; i++){

		scanf("%d",&tmp);
		V.push_back(Info(tmp,i));
	}

	sort(V.begin(),V.end());

	for(int i = 0; i < V.size(); i++){

		table[V[i].loc] = i;
	}

	for(int i = 0; i < N; i++){

		if(table[i] < N/2){

			printf("%d\n",V[N/2].value);

		}else{

			printf("%d\n",V[N/2-1].value);
		}
	}

	return 0;
}
