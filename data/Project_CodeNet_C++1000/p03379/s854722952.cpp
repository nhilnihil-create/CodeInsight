#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> X(N),Y(N);
  for(int i=0;i<N;i++){
    cin >> X.at(i);
    Y.at(i) = X.at(i);
  }
  sort(Y.begin(),Y.end());
  
  long long left,right;
  right = Y.at(N/2);
  left = Y.at(N/2-1);
  
  for( int i=0;i<N;i++){
    if(X.at(i) < right) cout << right << endl;
    else cout << left << endl;
  }  
}