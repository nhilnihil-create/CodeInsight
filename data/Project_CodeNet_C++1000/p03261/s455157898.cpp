#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string>A(N);
  for(int i=0; i<N; i++)cin >> A.at(i);
  
  string ans="Yes";
  
  for(int i=0; i<N-1; i++){
    if(A.at(i).at(A.at(i).size()-1)!=A.at(i+1).at(0))ans="No";
  }
  
  sort(A.begin(), A.end());
  
  for(int i=0; i<N-1; i++){
    if(A.at(i)==A.at(i+1))ans="No";
  }
  
  cout << ans << endl;
}