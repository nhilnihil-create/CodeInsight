#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int n, m;
vector<int> e[50];

bool judge(int a,int b){
  bool checked[50];
  fill(checked, checked + 50, false);
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int x = q.front();
    q.pop();
    checked[x] = true;
    for(int y : e[x]){
      if(checked[y]) continue;
      if((x == a && y == b)|| (x == b && y == a)) continue;
      q.push(y);
      
    }
  }
  for(int i = 0; i < n; i++) if(!checked[i]) return true;
  return false;
}

int main(){
  cin >> n >> m;
  P p[50];
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--;b--;
    e[a].push_back(b); e[b].push_back(a);
    p[i] = P(a, b);
  }
  int ans = 0;
  for(int i = 0; i < m; i++){
    if(judge(p[i].first, p[i].second)) ans++;
  }
  cout << ans <<endl;
}
  