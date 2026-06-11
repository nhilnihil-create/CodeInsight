#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;

  vector<int> x(N);
  vector<int> y(M);

  for (int i = 0; i < N; i++)
  {
    cin >> x.at(i);
  }
  
  for (int i = 0; i < M; i++)
  {
    cin >> y.at(i);
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  int x_max = x.at(N - 1);
  int y_min = y.at(0);

  

  for (int i = X; i < Y + 1; i++){
    if (i > X && Y >= i && i > x_max && i <= y_min){
      cout << "No War" << endl;
      return 0;
    }
  }
  cout << "War" << endl;
}