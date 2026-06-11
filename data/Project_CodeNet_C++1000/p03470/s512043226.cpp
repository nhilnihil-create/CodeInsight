#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cin >> n ;
  vector<int> M(n); 

  for (int i=0;i<n;i++){
    cin >> M.at(i) ;
  }

  sort(M.begin(),M.end());
  reverse(M.begin(),M.end());

  int c=0;

  for (int j=0;j+1<n;j++){
    if(M.at(j) > M.at(j+1))
    c++;
  }
  cout << c+1 << endl;
}
