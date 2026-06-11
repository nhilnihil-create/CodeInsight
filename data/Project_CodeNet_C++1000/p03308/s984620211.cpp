#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0; i < N; i++){
    cin >> A.at(i);
  }
  sort(A.begin(),A.end());
  cout << A.back() - A.front();
  return 0;
}