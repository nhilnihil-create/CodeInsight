#include <bits/stdc++.h>
using namespace std;

vector<bool> ans(40,false);
void intto(int n,int keta){
  if(n == 0) return;
  if(n%2 == 1 || n%2 == -1){
    ans[keta] = true;
    --n;
  }
  intto(n/(-2),keta+1);
}

int main(){
  int n;
  cin >> n;
  intto(n,0);
  while(ans.size() > 0 && !ans[ans.size()-1]) ans.pop_back();
  reverse(ans.begin(),ans.end());
  for(int i=0; i<(int)ans.size(); ++i){
    if(ans[i]) cout << 1;
    else cout << 0;
  }
  if(ans.size() == 0) cout << 0;
  cout << endl;
}