#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,T,A;
  cin >> N >> T >> A;
  
  vector<int> H(N);
  double min = 10000;
  int target = 0;
  
  for(int i=0; i<N; i++){
    cin >> H.at(i);
    
    double temp = T - 0.006 * H.at(i);
    double dif = abs(A-temp);
    if(min > dif){
      min = dif;
      target = i + 1;
    }
  }
  
  cout << target << endl;
}
