#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  vector<int> a(5);rep(i,5) cin >> a[i];
  int k; cin >> k;

  bool flag = true;
  rep(i,5){
    for(int j = i+1;j<5;j++){
      if(abs(a[i]-a[j])>k) flag = false;
    }
  }  

  if(flag) cout << "Yay!" << endl;
  else cout << ":(" << endl;
    
  return 0;
}
