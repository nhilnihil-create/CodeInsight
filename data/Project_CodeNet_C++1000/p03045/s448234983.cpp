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
int boss[SIZE],height[SIZE];

//自分のボスのindexを取得しつつ、経路圧縮を行う関数
int get_boss(int id){
	if(boss[id] == id)return id; //自分が代表なら、自分の値を返す
	else{
		return boss[id] = get_boss(boss[id]); //代表でないなら、自分が所属する組織の代表を返しつつ、経路圧縮
	}
}


void unite(int x,int y){
	int boss_x = get_boss(x);
	int boss_y = get_boss(y);

	//既に同じグループなら何もしない
	if(boss_x == boss_y)return;

	//高さが高い方に吸収する
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

		boss[i] = i;
		height[i] = 0;
	}

	int a,b,z;

	for(int i = 0; i < M; i++){

		scanf("%d %d %d",&a,&b,&z);
		a--;
		b--;

		unite(a,b);
	}

	int ans = 0;
	for(int i = 0; i < N; i++){

		if(get_boss(i) == i){
			ans++;
		}
	}

	printf("%d\n",ans);

	return 0;
}
