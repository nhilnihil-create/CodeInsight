#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n,i,ans = 0;cin >> n;int a[n];
  for(i=0;i<n;i++) cin >> a[i];
  for(i=1;i<n;i++){
    if(a[i]==a[i-1]){
      ans++;a[i] = -1;
    }
  }
  cout << ans << endl;
}