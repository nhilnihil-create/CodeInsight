#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,D,X;
  cin >> N >> D >> X;
  vector<int>vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
    X += (D-1)/vec[i]+1;
  }
  cout << X << endl;
}
