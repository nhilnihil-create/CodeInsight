#include <bits/stdc++.h>
using namespace std;

int main(){
  const int Ndata= 5;
  vector<int> data(Ndata);
  for(int i=0; i<Ndata; i++){
    cin >> data.at(i);
  }
  int K;
  cin >> K;

  string ans= (data.at(Ndata-1)- data.at(0) > K) ? ":("
                                                 : "Yay!";

  cout << ans << endl;
}