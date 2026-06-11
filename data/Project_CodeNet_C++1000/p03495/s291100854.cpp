#include "bits/stdc++.h"
using namespace std;

int main() {
  int N,K;
  cin >> N >> K ;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  
  unordered_map<int,int> num;
  for(int i=0;i<N;i++){
    if(num.count(A.at(i))){
      num.at(A.at(i))++;
    }else{
      num[A.at(i)] = 1;
    }
  }
  vector<int> ballnum;
  for(auto p : num){
    int value = p.second;
    ballnum.push_back(value);
  }
  sort(ballnum.begin(), ballnum.end());
  int res = 0;
  for(int i=0;i<max((int)num.size()-K, 0);i++){
    res += ballnum.at(i);
  }
  cout << res << endl;
  return 0;
}