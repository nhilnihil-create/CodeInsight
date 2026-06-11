#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,T,A;
  cin >> N >> T >> A;
  vector<int> H(N+1);
  double better_T_abs = 10000;
  int better_index;
  for(int i=1; i < N+1 ; i++){
    cin >> H.at(i);
    if(better_T_abs > double(abs(A -(T-H.at(i)*0.006)))){
      better_T_abs = double(abs(A-(T-H.at(i)*0.006)));
      better_index = i;
    }
    
  }
  cout << better_index << endl;
}