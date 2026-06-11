#include<bits/stdc++.h>
using namespace std;

int main(){
  //nは木の本数、kは電飾を施す木の本数
  int n,k;
  cin >> n >> k;
  
  vector<int> vec(n);
  for(int i = 0;i < n;i ++){
    cin >> vec.at(i);
  }
  
  sort(vec.begin(),vec.end());
  
  vector<int> sa(n - 1);
  for(int i = 0;i < n - 1;i ++){
    sa.at(i) = vec.at(i + 1) - vec.at(i);
  }
  
  int ans = 0;
  
  for(int i = 0;i < n - k + 1;i ++){
    int kazu = 0;
    for(int j = 0;j < k - 1;j ++){
      kazu += sa.at(j + i);
    }
    if(i == 0)ans = kazu;
    else {
      if(ans > kazu)ans = kazu;
    }
  }
  
  cout << ans << endl;
}