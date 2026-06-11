#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>data(N);
  int M=0;
  int m=1000000000;
  for(int i;i<N;i++){
    cin >> data.at(i);
    if(data.at(i)>M) M=data.at(i);
    if(data.at(i)<m) m=data.at(i);
  }
  cout << M-m << endl;
}
