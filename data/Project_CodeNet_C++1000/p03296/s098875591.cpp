#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int ans = 0;
  int pre;
  cin >> pre;
  for(int i = 0; i < n-1; i++){
    int a;
    cin >> a;
    if(pre == a){
      ans++;
      pre = -1;
    }
    else pre = a;
  }
  cout << ans << endl;
  return 0;
}