#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  int i;
  int ans = 0;
  for(i=0;i<n;i++){
    cin >> a[i];
    if(i>=1 && a[i]==a[i-1]){
      ans++;
      a[i]=-1;
    }
  }
  cout << ans << endl;
}
