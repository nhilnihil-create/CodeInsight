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

ll N, M;
vector <int> Graph[int(1e5+5)];
bool two = true;
bool visited[int(1e5+5)], color[int(1e5+5)];

int Check(){
  visited[1] = true;
  queue <int> que; que.push(1);
  while (!que.empty()){
    int Q = que.front(); que.pop();
    for (int v : Graph[Q]){
      if (!visited[v]){
        que.push(v);
        visited[v] = true;
        color[v] = 1 - color[Q];
      }else{
        if (color[v] == color[Q]){
          two = false;
          return 0;
        }
      }
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
  Check();

  if (!two){
    cout << N * (N - 1) / 2 - M << endl;
    return 0;
  }

  ll cnt[2] = {};
  for (int i = 1; i <= N; i++){
    cnt[color[i]]++;
  }
  cout << cnt[0] * cnt[1] - M << endl;

  return 0;
}
