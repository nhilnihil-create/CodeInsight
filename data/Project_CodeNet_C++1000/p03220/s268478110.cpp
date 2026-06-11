#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,T,A;
  cin >> N >> T >> A;
  vector<int> H(N);
  for(int i=0;i<N;i++){
    cin >> H.at(i);
  }
  int bangou=0;
  double min_distance=100000;
  for(int i=0;i<N;i++){
    double B=T-H.at(i)*0.006;
    if(abs(A-B)<=min_distance){
      min_distance=abs(A-B);
      bangou=i+1;
    }
  }
  cout << bangou << endl;
}  