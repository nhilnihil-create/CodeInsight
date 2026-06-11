#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  vector<int> X(4);

  for(int i = 0; i < 4; i++)
    cin >> X[i];

  sort(X.begin(), X.end());

  if(X[0]==1&&X[1]==4&&X[2]==7&&X[3]==9)
  cout << "YES" << endl;
  else
  {
    cout << "NO" << endl;
  }
  
}