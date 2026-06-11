#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/*
*/

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b){
  return a/gcd(a,b) * b;
}
ll func2(ll n){
  ll res = 0;
  while(n%2 == 0){
    n /= 2;
    res++;
  }
  return res;
}

ll zyou(ll a,ll b){//a＾b
  ll res = 1;
  for(int i = 1;i<=b;i++){
    res *= a;
  }
  return res;
}
struct Edge{
  int to;
  int weight;
  Edge(int t, int w) : to(t),weight(w){ }
};

typedef pair<int,int> P;
using Graph = vector<vector<int>>;

ll calc(ll a, ll b, ll p){//aのb乗をpで割った余り
  if(b == 0) return 1;

  else if(b%2 == 0){
    ll d = calc(a,b/2,p);
    return (d*d)%p;
  }
  else if(b%2 == 1){
    return (a * calc(a,b-1,p))%p;
  }
}


bool is_prime(int n){//nが素数であるかどうか判定 iで割り切れると素数でない
    if(n == 1) return false;//1は例外
    for(int i = 2;i*i <= n;i++){
        if(n%i == 0) return false;
    }
    
    return true;
}

bool palin(string S){//回文判定
  int n = S.size();
  bool flag = true;
  if(n%2 == 0){
    for(int i = 0;i<=n/2-1;i++){
      if(S[i] != S[n-i-1]){
        flag = false;
        break;
      }
    }
  }
  else if(n%2 == 1){
    for(int i = 0;i<=n/2-1;i++){
      if(S[i] != S[n-i-1]){
        flag = false;
        break;
      }
    }
  }
  return flag;
}
/*vector<int> d(N+1,-1);

//頂点xとの各点との最短距離を求める
void bfs(int x,Graph &G){
  d[x] = 0;
  queue<<int> que;
  que.push(x);

  // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
}*/

int main(){
  int N,A,B;
  cin >> N >> A >> B;
  vector<int> P(N);
  rep(i,N){
    cin >> P[i];
  }
  int c1 = 0;//A以下の数
  int c2 = 0;//A+1以上B以下
  int c3 = 0;//B＋１以上
  rep(i,N){
    if(P[i] <= A) c1++;
    if(P[i] >= A +1 && P[i] <= B) c2++;
    if(P[i] >= B+1) c3++;
  }
  cout << min(c1,min(c2,c3)) << endl;

  
 }
