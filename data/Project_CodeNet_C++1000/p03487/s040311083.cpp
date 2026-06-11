#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int n, ans=0;
  cin >> n;
  vector<int> k(n+1, 0);
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    if(n<a){
      ans++;
      continue;
    }
    k[a]++;
  }
  for(int i=0; i<=n; i++){
    if(k[i]>i) ans+=k[i]-i;
    else if(k[i]<i) ans+=k[i];
  }
  cout << ans << endl;
  return 0;
}
