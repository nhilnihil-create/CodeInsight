#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
int n,m,De[2020202][2];
char S[2020202];
bool Out[2020202];
vector <int> Vec[202020];
stack <int> St;
int main(){
	scanf("%d %d",&n,&m);
	scanf("%s",S+1);
	for (int i=1;i<=m;i++){
		int x,y; scanf("%d %d",&x,&y);
		De[x][S[y]-'A']++; De[y][S[x]-'A']++;
		Vec[x].push_back(y);
		Vec[y].push_back(x);
	}
	for (int i=1;i<=n;i++) if (!De[i][0]||!De[i][1])
		St.push(i),Out[i]=1;;
	while (!St.empty()){
		int x=St.top(); St.pop(); 
		for (int i=0;i<Vec[x].size();i++){
			int y=Vec[x][i];
			if (Out[y]) continue;
			De[y][S[x]-'A']--;
			if (!De[y][0]||!De[y][1]){
				Out[y]=1; St.push(y);
			}
		}
	}
	for (int i=1;i<=n;i++) if (!Out[i]){
		cout<<"Yes"; return 0;
	}
	cout<<"No";
}