#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(){
  int N, M;
  cin >> N >> M;
  char e[N][M];
  rep(i, N)rep(j, M)cin >> e[i][j];
  bool ans = true;
  rep(i, N)rep(j, M){
    if (e[i][j] == '#'){
      bool flag = false;
      rep(k, 4){
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx >= 0 && ny >= 0 && nx < N && ny < M){
          if (e[nx][ny] == '#'){
            flag = true;
          }
        }
      }
      if (flag) continue;
      else ans = false;
    }
  }
  if (ans) cout << "Yes" <<endl;
  else cout << "No" <<endl;
}      