#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>value(N);
  for(int i=0;i<N;i++){
    cin >> value.at(i);
  }
  vector<int>cost(N);
  for(int i=0;i<N;i++){
    cin >> cost.at(i);
  }
  int ans=0;
  for(int i=0;i<N;i++){
    if(value.at(i)>cost.at(i)) ans+=value.at(i)-cost.at(i);
  }
  cout << ans << endl;
}