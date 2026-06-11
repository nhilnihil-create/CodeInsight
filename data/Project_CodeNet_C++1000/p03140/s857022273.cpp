#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  string a,b,c; cin >> a >> b >> c;
  int ans = 0;
  for(int i = 0; i < n; ++i){
    ans += set<char>({a[i],b[i],c[i]}).size() - 1;
  }
  cout << ans << endl;
}