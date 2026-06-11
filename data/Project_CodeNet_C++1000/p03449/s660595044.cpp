#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<int> A(N),B(N);
  vector<int> sum_n(N,0);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  for(int i=0;i<N;i++){
    cin >> B.at(i);
  }
  
  for(int i=0;i<N;i++){
    sum_n.at(i) += A.at(0);
    for(int j=1;j<=i;j++){
      sum_n.at(i) += A.at(j);
    }
    for(int j=i;j<N;j++){
      sum_n.at(i) += B.at(j);
    }    
  }
  sort(sum_n.begin(),sum_n.end());
  cout << sum_n.at(N-1) << endl;
}