#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = pow(10, 9) + 7;
//const int MOD = 998244353;
//const int MOD = ;
int mod(int A, int M) {return (A % M + M) % M;}
const int INF = 1LL << 60;
template <class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
int divCeil(int A, int B) {return (A + (B - 1)) / B;}
int myctoi(char C) {return C - 48;}
char myitoc(int N) {return '0' + N;}

template <class A> class unionfind
{
public:
  vector<int> parent;
  vector<int> rank;
  vector<A> diffw;

  unionfind(int N, A U = 0)
  {
    parent = vector<int>(N, -1);
    rank = vector<int>(N, 0);
    diffw = vector<A>(N, U);
  }

  int root(int X)
  {
    if (parent.at(X) < 0) return X;
    int R = root(parent.at(X));
    diffw.at(X) += diffw.at(parent.at(X));
    return parent.at(X) = R;
  }

  int size(int X)
  {
    return -parent.at(root(X));
  }

  A weight(int X)
  {
    root(X);
    return diffw.at(X);
  }

  A diff(int X, int Y)
  {
    return weight(Y) - weight(X);
  }

  bool same(int X, int Y)
  {
    return (root(X) == root(Y));
  }

  bool unite(int X, int Y, A W)
  {
    W += weight(X);
    W -= weight(Y);

    X = root(X);
    Y = root(Y);
    if (X == Y) return false;
    
    if (rank.at(X) < rank.at(Y)) 
    {
      swap(X, Y);
      W = -W;
    }
    if (rank.at(X) == rank.at(Y)) rank.at(X)++;
    parent.at(X) += parent.at(Y);
    parent.at(Y) = X;
    diffw.at(Y) = W;
    return true;
  }
};

signed main()
{
  int N, M;
  cin >> N >> M;

  unionfind<int> uf(N);

  for (int i = 0; i < M; i++)
  {
    int L, R, D;
    cin >> L >> R >> D;
    L--; R--;
    if (uf.same(L, R))
    {
      if (abs(uf.diff(L, R)) != D)
      {
        cout << "No" << endl;
        return 0;
      }
    }
    else
      uf.unite(L, R, D);
  }

  cout << "Yes" << endl;

  for (int i = 0; i < N; i++)
  {
    uf.root(i);
    cerr << uf.parent.at(i) << " " << uf.rank.at(i)
         << " " << uf.diffw.at(i) << endl;
  }
}