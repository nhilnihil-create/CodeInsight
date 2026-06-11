#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  
  int w_num=0,b_num=0;
  vector<int> w_l(n+1),b_l(n+1);
  
  w_l[0]=0;
  b_l[0]=0;
  
  for (int i; i<n; i++){
    if (s.at(i)=='.'){
      w_num+=1;
    }
    else {
      b_num+=1;
    }
    w_l[i+1]=w_num;
    b_l[i+1]=b_num;
  }
  
  int ans=100000;
  for (int j; j<n+1; j++){
    ans=min(ans,b_l[j]+w_num-w_l[j]);
  }
  cout << ans << endl;
}