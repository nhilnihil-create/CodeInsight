#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  vector<int> P(3);
  for(int i=0; i<N; i++){
    int p;
    cin >> p;
    if(p<=A) P.at(0)++;
    else if(p<=B) P.at(1)++;
    else P.at(2)++;
  }
  int ans = min({P.at(0), P.at(1), P.at(2)});
  cout << ans << endl;
}