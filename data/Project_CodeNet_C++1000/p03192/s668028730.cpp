#include <bits/stdc++.h>
using namespace std;

int main(){
  string N;
  cin >> N;

  int ans=0;
  for(int i=0;i<N.size();i++) if(N.at(i)=='2')  ans++;
  cout << ans << endl;

  return 0;
}