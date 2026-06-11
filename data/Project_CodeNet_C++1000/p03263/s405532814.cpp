#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define PRINT(v) for (auto x : (V)) cout <<x <<" " <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> struct edge { int from, to; T cost;};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}
void hey(){ cout <<"hey" <<endl; }


vector<int> di = {0,1};
vector<int> dj = {1,0};

int main() {
  int h,w; cin >>h >>w;
  vector<vector<int>> field(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >>field[i][j];
  int n = 0;
  queue<int> que;
  rep(i, h){
    rep(j, w){
      if (field[i][j] % 2 == 0) continue;
      // 奇数なら右か下に1押し付ける
      rep(k, di.size()){
        int ni = i + di[k];
        int nj = j + dj[k];
        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        field[ni][nj]++;
        field[i][j]--;
        que.push(i+1); que.push(j+1);
        que.push(ni+1); que.push(nj+1);
        n++;
        break;
      }
    }
  }
  cout <<n <<endl;
  rep(i, n){
    rep(j, 4){
      cout <<que.front();
      if (j == 3) cout <<endl;
      else cout <<" ";
      que.pop();
    }
  }
}
