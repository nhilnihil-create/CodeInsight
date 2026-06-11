#include<bits/stdc++.h>
using namespace std;


int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  vector<int> ans(10,0);
  ans[a]++;
  ans[b]++;
  ans[c]++;
  ans[d]++;
  if(ans[1]==1 && ans[4]==1 && ans[7]==1 && ans[9]==1){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}
