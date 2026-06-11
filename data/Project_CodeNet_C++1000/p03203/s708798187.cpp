#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
int H , W , n;

int x[N] , y[N] , first[N] , res;
map<int,int> ban[N];

int main(){
	scanf("%d%d%d",&H,&W,&n);
	for (int i = 1;i <= n;i++){
		scanf("%d%d",x+i,y+i);		
		ban[x[i]][y[i]] = 1;
	}
	
	for (int i = 1;i <= W;i++) first[i] = H + 1;
	
	first[1] = 1;
	
	for (int i = 2;i <= W;i++){
		int now = first[i - 1] + 1;
		
		while (ban[now][i]) now++;
		if (now >= H + 1) break;
		first[i] = now;
	}
	
//	for (int i = 1;i <= W;i++) printf("[%d %d]\n",i,first[i]);
	
	int res = H;
	for (int i = 1;i <= n;i++){
		if (x[i] >= y[i] + 1 && first[y[i]] <= x[i]){
			res = min(res , x[i] - 1);
		}
	}
	cout<<res;
	return 0;
}