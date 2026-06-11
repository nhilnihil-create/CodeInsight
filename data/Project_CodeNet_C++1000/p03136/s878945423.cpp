#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,X=0;
  cin >> N;
  vector<int>vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  sort(vec.begin(),vec.end());
  for(int j=0; j < N-1; j++){
    X += vec[j];
  }
  if(X > vec[N-1]){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}
