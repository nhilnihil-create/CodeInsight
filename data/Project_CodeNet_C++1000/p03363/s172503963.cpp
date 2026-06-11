#include<iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility> // pair, tuple, swap
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  vector<long long> B(N+1);//partial sum
  B.at(0) = 0;
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    B.at(i+1) = B.at(i) + A.at(i);
  }
  map<long long, long long> cnt;
  for(int i=0;i<=N;i++){
    long long num = B.at(i);
    if(cnt.count(num)){
      cnt.at(num)++;
    }else{
      cnt[num] = 1;
    }
  }
  long long result = 0;
  for(pair<int, long long> p : cnt){
    result += p.second*(p.second-1)/2;
  }
  cout << result << endl;
  return 0;
}