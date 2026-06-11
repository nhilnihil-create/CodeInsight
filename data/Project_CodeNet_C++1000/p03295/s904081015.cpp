#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 100005


struct Data{
	Data(int arg_left,int arg_right){
		left = arg_left;
		right = arg_right;
	}
	bool operator<(const struct Data &arg) const{

		return right < arg.right;
	}

	int left,right;
};

int main(){

	int N,M;
	scanf("%d %d",&N,&M);

	int left,right;
	vector<Data> D;

	for(int i = 0; i < M; i++){

		scanf("%d %d",&left,&right);
		left--;
		right--;
		D.push_back(Data(left,right));
	}

	sort(D.begin(),D.end());

	int last = -1;
	int ans = 0;

	for(int i = 0; i < D.size(); i++){

		if(D[i].left <= last){

			continue;
		}else{

			ans++;
			last = D[i].right-1;
		}
	}

	printf("%d\n",ans);

	return 0;
}
