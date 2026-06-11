#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n, a[200009];
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(long long i=0;i<n;i++){
    if(a[i]>i){
      cout << -1 <<  endl;
      return 0;
    }
  }
  long long prev=a[n-1];
  long long top=a[n-1];
  long long ans=0;
  long long top_idx = n-1;
  for(long long i=n-2;i>=0;i--){
    if(a[i]<top-(top_idx-i)){
      cout << -1 << endl;
      return 0;
    }
    else if(a[i]>prev-1){
      ans += top;
      top = a[i];
      top_idx = i;
    }
    prev = a[i];
  }
  ans += top;
  cout << ans << endl;
}
