#include <bits/stdc++.h>
using namespace std;
int main () {
  int N, A, B;
  cin >> N >> A >> B;
  vector<long> data(3);
  long a;
  for(int i = 0; i < N; i++){
    cin >> a;
    if(a <= A)data.at(0)++;
    else if(a >= A + 1 && a <= B)data.at(1)++;
    else data.at(2)++;
  }
  cout << min(data.at(0), min(data.at(1), data.at(2))) << endl;
  return 0;
}
