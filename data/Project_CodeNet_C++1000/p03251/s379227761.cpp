#include <iostream>

using namespace std;

int main() {
  int N, M, Xmax, Ymin; cin >> N >> M >> Xmax >> Ymin;
  for(int i = 0; i < N; i++) {
    int num; cin >> num;
    if(num > Xmax) Xmax = num;
  }
  for(int i = 0; i < M; i++) {
    int num; cin >> num;
    if(num < Ymin) Ymin = num;
  }
  if(Ymin - Xmax > 0) cout << "No War" << endl;
  else cout << "War" << endl;
  return 0;
}