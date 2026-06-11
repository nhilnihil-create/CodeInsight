#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,sum;
  cin >> N;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin >> vec[i];
  }
  sum=N;
  sort(vec.begin(),vec.end());
  for(int i=0;i<N-1;i++){
    if(vec[i] == vec[i+1]) sum -= 1;
  }
  cout << sum;
  return 0;
}