#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;

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

int N, M, ans;
vector <int> Graph[55];
bool visited[55];

int Check(int s, int t){
  fill(visited, visited + N + 1, false);

  queue <int> que; que.push(s);
  visited[s] = true;
  while (!que.empty()){
    int Q = que.front(); que.pop();
    for (int j : Graph[Q]){
      if (Q == s && j == t) continue;
      if (Q == t && j == s) continue;
      if (visited[j]) continue;
      visited[j] = true; que.push(j);
    }
  }

  for (int i = 1; i <= N; i++){
    if (!visited[i]){
      ans++; return 0;
    }
  }

  return 0;
}

int main(){
  cin >> N >> M;
  for (int i = 0; i < M; i++){
    int A, B; cin >> A >> B;
    Graph[A].push_back(B);
    Graph[B].push_back(A);
  }

  for (int i = 0; i < N; i++){
    for (int j : Graph[i]){
      if (i > j) continue;
      Check(i, j);
    }
  }
  cout << ans << endl;

  return 0;
}
