#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int N, M;
vector <int> Graph[int(1e5+5)], Rev[int(1e5+5)];
int ans[int(1e5+5)];
bool visited[int(1e5+5)];

int DFS(int before, int now){

  for (int i = 0; i < Rev[now].size(); i++){
    int next = Rev[now][i];
    if (!visited[next]) return 0;
  }

  visited[now] = true;
  ans[now] = before;

  for (int i = 0; i < Graph[now].size(); i++){
    int next = Graph[now][i];
    if (!visited[next]) DFS(now, next);
  }

  return 0;
}

int main(){
  cin >> N >> M;
  for (int i = 0; i < N + M - 1; i++){
    int A, B; cin >> A >> B;
    Graph[A].push_back(B);
    Rev[B].push_back(A);
  }

  for (int i = 1; i <= N; i++){
    if (Rev[i].size() == 0){
      DFS(0, i);
    }
  }

  for (int i = 1; i <= N; i++) cout << ans[i] << endl;

  return 0;
}
