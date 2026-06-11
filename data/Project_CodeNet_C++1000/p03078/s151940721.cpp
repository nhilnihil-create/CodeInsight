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
  int X,Y,Z; cin >>X >>Y >>Z;
  int K; cin >>K;
  vector<ll> A(X); rep(i, X) cin >>A[i];
  vector<ll> B(Y); rep(i, Y) cin >>B[i];
  vector<ll> C(Z); rep(i, Z) cin >>C[i];
  sort(allR(A)); sort(allR(B)); sort(allR(C));
  // A[i],B[j],C[k] を選ぶとして、自分より絶対に美味しい組は
  // (i+1)*(j+1)*(k+1)-1 個ある
  priority_queue<ll> pq;
  for (int i=0; i<X; i++){
    for (int j=0; j<Y; j++){
      if ((i+1)*(j+1) > K) break;
      for (int k=0; k<Z; k++){
        if ((i+1)*(j+1)*(k+1) > K) break;
        pq.push(A[i]+B[j]+C[k]);
      }
    }
  }
  for (int i=0; i<K; i++){
    cout <<pq.top() <<endl;
    pq.pop();
  }
}