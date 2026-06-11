#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> P(N);
  int Max=0;
  int Sum=0;
  for(int i=0; i<N; i++){
    cin >> P.at(i);
    Max=max(P.at(i), Max);
    Sum+=P.at(i);
  }
  cout << Sum-Max/2 << endl;
}
  