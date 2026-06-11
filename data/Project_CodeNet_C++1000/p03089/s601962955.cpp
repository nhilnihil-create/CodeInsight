#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;  cin >> n;
  vector<int> b(n), ans(n);
  for(int i=0; i<n; i++)  cin >> b[i];
  bool all_done = true;
  int point = -1, cnt = 0;
  for(int j=0; j<n; j++){
    point = -1, cnt = 0;
    for(int i=0; i<n; i++)
      if(b[i] != -1)
        if(b[i] == ++cnt)  point = i;
    if(point == -1){
      all_done = false;
      break;
    }else{
      ans[j] = b[point];
      b[point] = -1;
    }
  }
  if(all_done){
    for(int i=n-1; i>=0; i--)
      cout << ans[i] << endl;
  }else{ 
    cout << "-1" << endl;
  }
  return 0;
}