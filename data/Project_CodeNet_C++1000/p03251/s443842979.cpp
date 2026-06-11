#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  int x[N];
  int y[M];
  for(int i = 0; i < N;i++) cin >> x[i];
  for(int i = 0; i < M; i++) cin >> y[i];
  sort(x, x+N);
  sort(y, y+M);
  int ymin = y[0];
  int xmax = x[N-1];
  bool outbreak = false;
  for(int i = X+1; i <=Y;i++){
    if(i>xmax && i <= ymin){
      outbreak = true;
      break;
    }
  }
  if(outbreak) cout << "No War" << endl;
  else cout << "War" << endl;
}
