#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n, a[100009], mx=0, mn=1e9;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
    mx = max(a[i], mx);
  }
  for(int i=0;i<n;i++){
    if(mx==a[i])continue;
    if(abs(a[i]-mx/2)<abs(mn-mx/2)){
      mn=a[i];
    }
  }
  cout << mx << ' ' << mn << endl;
}

