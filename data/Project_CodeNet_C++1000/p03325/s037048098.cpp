#include <bits/stdc++.h>
using namespace std;

int main() {
int N;
  cin >> N;
vector<int> data(N);
  for(int i=0;i<N;i++){
  cin >> data.at(i);
  }
int count = 0;
  for(int i=0;i<N;i++){
  while(data.at(i) > 0){
  if(data.at(i)%2 == 0){
  data.at(i) /= 2;
  count++;
  }
  else{
  break;
  }
  }
  }
  cout << count;
}