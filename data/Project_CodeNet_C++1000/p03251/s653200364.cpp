#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int N, M, X, Y;
  bool war = false;
  cin >> N >> M >> X >> Y;
  vector<int> x(N);
  vector<int> y(M);
  
  for(int i = 0; i< N; i++){
    cin >> x[i];
  }
  for(int i = 0; i< M; i++){
    cin >> y[i];
  }

  for (int i = X + 1; i < Y + 1; i++) {
    for (int j = 0; j < N; j++) {
      if(x[j] >= i){
        war = true;
        break;
      }
    }
    for (int j = 0; j < M; j++) {
      if(y[j] < i){
        war = true;
        break;
      }
    }
    if(war == false){
      cout << "No War" << endl;
      return 0;
    }
    war = false;
  }
  cout << "War" << endl;
  return 0;
}
