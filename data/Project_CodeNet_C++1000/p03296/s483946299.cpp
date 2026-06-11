#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll oddxor(ll a){
   return ((a+1)/2)%2 ;
}
ll funcxor(ll b){
   if(b%2) return oddxor(b);
   else return oddxor(b+1)^(b+1);
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0;i<n;i++){
   cin >> a[i];
  }
  //ある要素とその後ろが同じ色なら、後ろの色を変える
  //隣り合う色が同じとき、後ろの色を変え、後ろの二個先を見る
  int ans = 0;
  for(int i = 0;i<n-1;){
   if(a[i]==a[i+1]){
     ans++;
     i += 2;
   }
    else i++;
  }
  cout << ans << endl;
}
