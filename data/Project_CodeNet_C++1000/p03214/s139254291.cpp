#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<double> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  
  double mean = 0;
  for(int j=0; j<N; j++){
    mean += vec.at(j);
  }
  mean = mean / N;
  
  double num_min = 100000000;
  int ans = 0;
  
  for(int k=0; k<N; k++){
    if(abs(vec.at(k) - mean) < num_min){
      num_min = abs(vec.at(k) - mean);
      ans = k;
    }
  }
  cout << ans << endl;
}