#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int cnt[1000006][2];
bool del[1000006];
vector <int> G[1000006];
char s[1000006];
queue <int> q;
int read(){
	int cnt = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		ch = getchar();
	while ('0' <= ch && ch <= '9'){
		cnt = cnt * 10 + ch - '0';
		ch = getchar();
	}
	return cnt;
}
int main(){
	int n = read(), m = read();
	cin >> s;
	for (int i = 1; i <= m; ++ i){
		int u = read(), v = read();
		cnt[u][s[v - 1] == 'B'] ++;
		cnt[v][s[u - 1] == 'B'] ++;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int del_cnt = 0;
	for (int i = 1; i <= n; ++ i)
		if (cnt[i][0] == 0 || cnt[i][1] == 0){
			del[i] = true;
			++ del_cnt;
			q.push(i);
		}
	while (! q.empty()){
		int u = q.front();
		q.pop();
		for (int i = 0; i < G[u].size(); ++ i){
			int v = G[u][i];
			if (! del[v]){
				cnt[v][s[u - 1] == 'B'] --;
				if (cnt[v][0] == 0 || cnt[v][1] == 0){
					++ del_cnt;
					del[v] = true;
					q.push(v);
				}
			}
		}
	}
	if (del_cnt == n)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}
