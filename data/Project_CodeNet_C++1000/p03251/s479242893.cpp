#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M,X,Y;
  cin >> N >> M >> X >> Y;
  
  vector<int>x(N);
  for (int i = 0; i < N; i++) {
    cin >> x.at(i);
  }
  sort(x.begin(), x.end());
    
  vector<int>y(M);
  for (int i = 0; i < M; i++) {
    cin >> y.at(i);
  }
  sort(y.begin(), y.end());
  
  if (x.at(N-1) < y.at(0) && x.at(N-1) < Y && y.at(0) > X){
    cout << "No War" << endl;
  }
  else {
    cout << "War" << endl;
  }
}
     