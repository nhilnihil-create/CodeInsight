#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,x;
  cin >> n >> m >> x;
  vector<int> r(m);
  for(int i = 0; i < m; i++){
    cin >> r[i];
  }
  int ans1 = 0, ans2 = 0;
  for(int i = x; i > 0; i--){
    for(int j = 0; j < m; j++){
      if(i == r[j]) ans1++;
    }
  }
  for(int i = x; i <= n; i++){
    for(int j = 0; j < m; j++){
      if(i == r[j]) ans2++;
    }
  }
  cout << min(ans1,ans2) << endl;
}