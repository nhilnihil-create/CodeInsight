#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N, K, i, n;
  cin >> N >> K;
  map<int, int> data;
  
  for(i=0; i<N; i++){
    cin >> n;
    data[n]++;
  }
  vector<int> vec(data.size());
  i = 0;
  for(auto p : data){
    vec[i] = p.second;
    i++;
  }  
  
  int Sum = 0;
  sort(vec.begin(), vec.end());
  for(i=0; i<(long long) vec.size()-K; i++){
    Sum += vec[i];
  }
  cout << Sum << endl;
  return 0;
}