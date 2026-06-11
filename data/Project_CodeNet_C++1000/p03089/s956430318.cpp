#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

  int n;
  cin >> n;

  vector<string>a(n),b(n);
  for(int i=0; i<n; i++){
    cin >> b[i];
  }
  
  for(int i=0; i<n; i++){
    for(int j=n-i; j>=1; j--){
      string s = to_string(j);
      if(b[j-1]==s){
        a[n-i-1]=s;
        for(int k=j-1; k<n-i-1; k++){
          b[k]=b[k+1];
        }
        b[n-i-1]="0";
        break;
      }
    }
  }
  
  for(int i=0; i<n; i++){
    if(b[i]!="0"){
      cout << -1 << endl;
      return 0;
    }
  }

  for(int i=0; i<n; i++){
    cout << a[i] << endl;
  }
}