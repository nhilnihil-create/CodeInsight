#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,m,max=0,sum=0;
  cin >> n;
  vector<string> blue(n);
  for(int i=0;i<n;i++){
    cin >> blue.at(i);
  }
  cin >> m;
    vector<string> red(m);
  for(int i=0;i<m;i++){
    cin >> red.at(i);
  }
  for(int i=0;i<n;i++){
    sum=0;
    string word = blue.at(i);
    for(int j=0;j<n;j++){
      if(blue.at(j)==word)
        sum++;
    }
    for(int j=0;j<m;j++){
      if(red.at(j)==word)
        sum--;
    }
    if(sum>max)
      max=sum;
  }
  cout << max << endl;
}