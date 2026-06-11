#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int a,b,k; cin >> a >> b >> k;
  set<int> ans;
  
  for(int i = a;i<a+k;i++)
    if(i<=b)
      ans.insert(i);

  for(int i = b;i>b-k;i--)
    if(i>=a)
      ans.insert(i);

  //sort(ans.begin(),ans.end());
  for(auto itr = ans.begin(); itr != ans.end(); itr++)
    cout << *itr << endl;
  
  return 0;
}
