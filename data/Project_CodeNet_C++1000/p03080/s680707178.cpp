#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string s;
  cin >> N >> s;
  int i=0;
  for(int k=0; k<N; ++k){
    if(s[k]=='R')
      ++i;
    else
      --i;
  }
  if(i>0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
