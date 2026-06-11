#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


struct Info{

	int x,y,h;
};
Info info[105];

int main(){

	int N;
	scanf("%d",&N);

	for(int i = 0; i < N; i++){

		scanf("%d %d %d",&info[i].x,&info[i].y,&info[i].h);
	}

	for(int Cx = 0; Cx <= 100; Cx++){
		for(int Cy = 0; Cy <= 100; Cy++){

			int H = -1;
			int maximum = BIG_NUM;
			bool FLG = true;

			for(int i = 0; i < N; i++){

				int minus = abs(info[i].x-Cx)+abs(info[i].y-Cy);

				if(info[i].h == 0){ //H <= minusであればよい

					if(H != -1 && H > minus){

						FLG = false;
						break;
					}
					maximum = min(maximum,minus);
					continue;
				}

				int tmp = abs(info[i].x-Cx)+abs(info[i].y-Cy)+info[i].h;

				if(H == -1){

					H = tmp;
				}else if(H != tmp){

					FLG = false;
					break;
				}
			}
			if(H > maximum)continue;
			if(FLG && H != -1){

				printf("%d %d %d\n",Cx,Cy,H);
				return 0;
			}
		}
	}

	return 0;
}
