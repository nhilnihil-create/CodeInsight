#include<bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;

int n, H, W;
vector<int> g[maxn];

int main() {
	scanf("%d%d%d", &H, &W, &n);
	for(int i = 1;i <= n;i ++) {
	  int x, y;
		scanf("%d%d", &x, &y);
    g[y].push_back(x);
	}
	for(int i = 1;i <= W;i ++) {
	  g[i].push_back(0);
		g[i].push_back(H + 1);
		sort(g[i].begin(),g[i].end());
	}
  //1
	int Ans = H, Sz, lst = -1;
	Sz = g[1].size();
	for(int i = 0;i < Sz;i ++) {
	  int x = g[1][i];
		if(x > 1) {
			Ans = min(Ans,x - 1);
			/*
			if(x - g[1][i - 1] > 1 && lst == -1) {
			  if(g[1][i - 1] > 1) lst = g[1][i - 1] + 1;
				else lst = 2;
			}
			*/
		}
	}
	lst = 2;
	for(int i = 2;i <= W;i ++) {
	  int Sz = g[i].size();
		for(int j = 0;j < Sz;j ++) {
		  int x = g[i][j];
			if(x <= i || x <= lst) continue;
      if(x - g[i][j - 1] > 1) {
				Ans = min(Ans,x - 1);
			  break;
			}
		}
		int flag = 0;
		for(int j = 0;j < Sz;j ++) {
		  int x = g[i][j];
			if(x <= lst + 1) continue;
      if(x - g[i][j - 1] > 1) {
			  int tmp = max(lst,g[i][j - 1] + 1);
				tmp ++; //tmp ++;
				lst = tmp;
//				cout << lst << ' ' << i << endl;
				flag = 1;
				break;
			}
		}
		if(!flag) lst = H + 5;
	}
	printf("%d\n", Ans);
  return 0;
}
