#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  long long asum = 0, bsum = 0;
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
    asum += (long long)a.at(i);
  }
  for(int i = 0; i < n; i++){
    cin >> b.at(i);
    bsum += (long long)b.at(i);
  }
  
  bool ok = true;
  if(asum < bsum) ok = false;
  if(!ok) cout << -1 << endl;
  else{
    int ans = 0;
    for(int i = 0; i < n; i++) a.at(i) -= b.at(i);
    sort(a.begin(), a.end());
    long long sum = 0;
    for(int i = 0; i < n; i++){
      if(a.at(i) >= 0) break;
      sum += (long long) a.at(i);
      ans++;
    }
    for(int i = n-1; i >= 0; i--){
      if(sum >= 0) break;
      sum += a.at(i);
      ans++;
    }
    
    cout << ans << endl;
  }
}