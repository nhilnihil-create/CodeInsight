#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

int N;
int c[100000];
vector<int> adj[10000];
map<pair<int, int>, int> edge_idx;
int d[10000];
bool visited[10000];

int main(){
  cin >> N;
  for(int i = 0; i < N - 1; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    edge_idx[make_pair(a, b)] = i;
    edge_idx[make_pair(b, a)] = i;
  }

  for(int i = 0; i < N; i++){
    cin >> c[i];
  }

  sort(c, c + N);
  long long M = 0;
  for(int i = 0; i < N - 1; i++){
    M += c[i];
  }
  cout << M << endl;

  int next_c_idx = N - 2;
  queue<int> que;
  que.push(0);
  visited[0] = true;
  d[0] = c[N - 1];
  while(!que.empty()){
    int now = que.front();
    que.pop();

    for(int i = 0; i < adj[now].size(); i++){
      int next = adj[now][i];
      if(!visited[next]){
	que.push(next);
	visited[next] = true;
	d[next] = c[next_c_idx];
	next_c_idx--;
      }
    }
  }
  for(int i = 0; i < N; i++){
    if(i){
      cout << ' ';
    }
    cout << d[i];
  }
  cout << endl;
}

  
