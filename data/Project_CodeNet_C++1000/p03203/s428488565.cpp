#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(123456789)
#define LINF (long long int)(123456789012345678)
#define MAX_V 1000

struct position{int x, y;};
bool cmp(position a, position b){
	return (a.x  < b.x);
}

int main(void){
	/*
	*ここから初期化なので読まなくて良い
	*/
	int H,W,N;
	cin>>H>>W>>N;
	int x,y;
	vector<position> p;
	rep(i,N){
		cin>>x>>y;
		position hoge = {x,y};
		p.push_back(hoge);
	}
	sort(p.begin(),p.end(),cmp);
	position now = {1,1};
	int pi = 0;
	/*
	*ここまで初期化なので読まなくて良い
	*/

	/*
	* now.x = 現在のx座標　now.y = 現在のy座標　これを動かしてシミュレーション
	* 高橋君は必ず右に進む
	* 青木君は上に進めるときは進んでおく()
	* 例えばnow.xが10, now.yが7だとする。
	* ここまで進んだということはx座標が9以下の障害物にぶつかれていないということをふまえると、
	* もしx,y = 11,3に障害物があったとして、この障害物に進むような手順があったことを証明できる。
	* つまり、yに関しては進めるだけ進んで、戻りたい時に戻れる。
	*/
	while(true){
		int memo = pi;//pという障害物をx座標昇順ソートした配列がある。 p[pi]と言った形で障害物を参照。初期値はpi=0。

		if(now.x == H){//すでに右端に到達してるなら現在のX座標が答え。
			cout<<now.x<<endl;
			return 0;
		}

		/*
		*now.xの一つ右 かつ now.y以下 の座標に障害物があれば、そこにぶつかるように調整できる。
		*/
		while(memo < N && now.x + 1 >= p[memo].x){//pはxについて昇順ソートされていることに注意。
			if((now.x+1==p[memo].x && now.y>=p[memo].y)){//もしぶつかれるならnow.xが答え。
				cout<<now.x<<endl;
				return 0;
			}else{//ぶつかれないなら次の障害物を確認.
				memo++;
			}
		}
		now.x++;//ぶつからなかったので右に移動。
		bool can = true;//上に移動できますか？
		while(pi < N && now.x >= p[pi].x){
			if(now.x==p[pi].x && now.y+1==p[pi].y){//上に移動できなかった場合
				can = false;
				pi++;//障害物を次に進める(そのxは通り越したので、もう見る必要はない)
			}else{
				pi++;//障害物を次に進める(そのxは通り越したので、もう見る必要はない)
			}
		}
		if(can){
			now.y++;
		}
	}
	return 0;
}