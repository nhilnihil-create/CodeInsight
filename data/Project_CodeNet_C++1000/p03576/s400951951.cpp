#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define allR(v) v.rbegin(), v.rend()
#define PRINT(v) for (auto x : (v)) cout <<x <<" " ; cout <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
typedef pair<int,int> Pi;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
const int inf = 1001001001;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
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

template<class T> struct edge { int to; T cost;};


int main() {
  int N,K; cin >>N >>K;
  vector<ll> X(N),Y(N),Xsort(N),Ysort(N);
  rep(i, N) cin >>X[i] >>Y[i];
  rep(i, N) Xsort[i] = X[i], Ysort[i] = Y[i];
  sort(all(Xsort)); sort(all(Ysort));
  ll res = 4000000000000000000;
  for (int l=0; l<N; l++){
    for (int r=l+1; r<N; r++){
      for (int d=0; d<N; d++){
        // 下左右を固定。
        // x1<=x<=x2, y1<=y<=y2を満たすような点がK個以上あるようなy2の最小値を求める
        ll x1 = Xsort[l];
        ll x2 = Xsort[r];
        ll y1 = Ysort[d];
        vector<ll> tmp;
        for (int i=0; i<N; i++){
          if (X[i] < x1 || x2 < X[i]) continue;
          if (Y[i] < y1) continue;
          tmp.push_back(Y[i]);
        }
        if (tmp.size() < K) continue;
        sort(all(tmp));
        ll y2 = tmp[K-1];
        chmin(res, abs(x1-x2)*abs(y1-y2));
      }
    }
  }
  cout <<res <<endl;
}
