#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> P(N);
  for(int i=0;i<N;i++){
    cin >> P.at(i);
  }
  sort(P.rbegin(),P.rend());
  P.at(0)/=2;
  int sum=0;
  for(int i=0;i<N;i++){
    sum+=P.at(i);
  }
  cout << sum << endl;
}
  
  