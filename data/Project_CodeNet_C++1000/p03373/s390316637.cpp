#include "bits/stdc++.h"
using namespace std;

int main() {
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y ;
  int N = max(X,Y);
  vector<long long> costArr;
  for(int i=0;i<=N;i++){ //C
    long long cost;
    cost = 2*C*i + max(0,A*(X-i)) + max(0,B*(Y-i));
    costArr.push_back(cost);
  }
  sort(costArr.begin(), costArr.end());
  cout << costArr.at(0) << endl;
  return 0;
}