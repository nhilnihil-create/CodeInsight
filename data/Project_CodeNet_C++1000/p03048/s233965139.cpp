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
vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1,0,-1};

vector<vector<char>> field(10, vector<char>(10));

//oと上下左右で隣接しているところは全てxに変える 
//全てのマスをxに変えるまで何回dfsを行ったかがoの連結数

//現在地(x,y)
void dfs(int x, int y) {
  //今いるところをxに変える

  field[x][y] = 'x';

  //移動する四方向をループ
  for (int i = 0; i < 4; i++) {

    //移動先をnx,nyとする
    int nx = x + dx[i], ny = y + dy[i];

    //nxとnyが地図の範囲内であるかどうかと移動先field[nx][ny]が陸地かどうかを判定
    if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && field[nx][ny] == 'o') dfs(nx,ny);

  }
  return;
}

//Sが偶文字列であるかどうか判定
bool hantei(string S) {
	int N = S.size();

	if(N%2) return false;

	else {
		string S1 = S.substr(0,N/2);
		string S2 = S.substr(N/2,N/2);
		if(S1 == S2) return true;
		else return false;
	}
}

int main(){
	int R,G,B,N;
	cin >> R >> G >> B >> N;
	ll ans = 0;
	for (int r = 0; r <= N/R; r++) {
		for (int g = 0; g <= N/G; g++) {
			if((N - r * R - g * G) % B == 0){
				int b = (N - r * R - g * G) / B;
				if(b >= 0) ans++;
			} 
		}
	}
	cout << ans << endl;
}
