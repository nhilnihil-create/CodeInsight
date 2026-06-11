#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005


int N,M;
int P[SIZE],loc[SIZE];
int boss[SIZE],height[SIZE];

int get_boss(int id){
	if(boss[id] == id)return id;
	else{
		return boss[id] = get_boss(boss[id]);
	}
}

int isSame(int x,int y){
	return get_boss(x) == get_boss(y);
}

void unite(int x,int y){
	int boss_x = get_boss(x);
	int boss_y = get_boss(y);

	if(boss_x == boss_y)return;

	if(height[boss_x] > height[boss_y]){

		boss[boss_y] = boss_x;

	}else if(height[boss_x] < height[boss_y]){

		boss[boss_x] = boss_y;

	}else{ //height[boss_x] == height[boss_y]

		boss[boss_y] = boss_x;
		height[x]++;
	}
}

int main(){

	scanf("%d %d",&N,&M);

	for(int i = 0; i < N; i++){

		scanf("%d",&P[i]);
		loc[P[i]] = i+1;
	}

	for(int i = 1; i <= N; i++){

		boss[i] = i;
		height[i] = 0;
	}

	int a,b;

	for(int i = 0; i < M; i++){

		scanf("%d %d",&a,&b);

		unite(a,b);
	}

	int ans = 0;
	for(int i = 1; i <= N; i++){

		if(isSame(i,loc[i])){

			ans++;
		}
	}

	printf("%d\n",ans);

	return 0;
}
