#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vector<int> x(N), y(M);
  for(int i = 0; i < N; i++) cin >> x[i];
  for(int i = 0; i < M; i++) cin >> y[i];
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  int Zx = x[N-1]+1, Zy = y[0];
  if(X < Zx && Zy <= Y && Zx <= Zy){
    cout << "No War" <<endl;
  } else{
    cout << "War" <<endl;
  }
}
