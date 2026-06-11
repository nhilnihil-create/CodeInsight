#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))


vector<int> edge[216000];
queue<int> q;
int n, m, a, b;
bool removed[216000];
bool loop[216000];
string s;
int cnt[216000][2];
int main(){
  cin >> n >> m >> s;
  for(int i = 0;i < m;i++){
    cin >> a >> b;a--,b--;
    if(a == b){
      loop[a] = true;
    }
    else{
      edge[a].push_back(b);
      edge[b].push_back(a);
    }
  }
  for(int i = 0;i < n;i++){
    for(int j = 0;j < edge[i].size();j++){
      int to = edge[i][j];
      cnt[i][s[to]-'A']++;
    }
    if(loop[i])cnt[i][s[i]-'A']++;
    if(cnt[i][0] == 0 || cnt[i][1] == 0){
      q.push(i);
    }
  }
  int remain = n;
  while(!q.empty()){
    int x = q.front();q.pop();
    if(removed[x])continue;
    removed[x] = true;
    remain--;
    for(int i = 0;i < edge[x].size();i++){
      int to = edge[x][i];
      if(removed[to])continue;
      if(--cnt[to][s[x]-'A'] == 0){
	q.push(to);
      }
    }
  }
  if(remain)cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}