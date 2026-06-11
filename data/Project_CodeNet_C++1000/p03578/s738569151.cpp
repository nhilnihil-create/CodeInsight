#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
template <typename T, typename U>
using P = pair<T,U>;
template <typename T>
using vt = vector<T>;
using vvi = vector<vector<int>>;

int main(){
  int N,M;
  bool f = true;
  cin >> N;
  vt<int> D(N);
  rep(i,N)  cin >> D[i];
  cin >> M;
  vt<int> T(M);
  rep(i,M)  cin >> T[i];

  sort(D.begin(),D.end());
  sort(T.begin(),T.end());
  if(M > N)
    f = false;
  else
  {
    int d = 0, t = 0;
    do
    {
      if(D[d] < T[t])
        d++;
      else if(D[d] == T[t])
      {
        t++; d++;
      }
      else
      {
        f = false;
        break;
      }
    }while(t < M);
  }

  cout << (f ? "YES" : "NO") << endl;

  return 0;
}