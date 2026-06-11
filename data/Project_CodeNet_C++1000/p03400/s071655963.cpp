#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,D,X,sum=0;
  cin >> N >> D >> X;
  vector<int> a(N);
  vector<int> b(N);
  for (int i=0;i<N;i++){
  cin >> a.at(i);
  b.at(i)=(D-1)/a.at(i)+1;
  sum+=b.at(i);
  }
  cout << sum+X << endl;
  
}