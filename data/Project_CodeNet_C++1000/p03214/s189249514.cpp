#include <bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  vector<double> data(N);
  double sum = 0;
  for(int i = 0; i < N; i++){
    cin >> data.at(i);
    sum += data.at(i);
  }
  sum /= N;
  double sub = 10000, a;
  for(int i = 0; i < N; i++){
    if(abs(sum - data.at(i)) < sub){
      a = i;
      sub = abs(sum - data.at(i));
    }
  }
  cout << a << endl;
  return 0;
}