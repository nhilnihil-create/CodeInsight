#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int n;
  cin >> n;
  int c[n], s[n], f[n];
  for(int i=0; i<n; i++){
    cin >> c[i] >> s[i] >> f[i];
  }
  for(int i=0; i<n-1; i++){
    int tmp = s[i]+c[i];
    for(int j=i+1; j<n-1; j++){
      if(tmp<s[j]){
        tmp = s[j]+c[j];
      }else{
        if((tmp-s[j])%f[j]==0){
          tmp += c[j];
        }else{
          tmp = s[j]+((tmp-s[j])/f[j]+1)*f[j]+c[j];
        }
      }
    }
    cout << tmp << endl;
  }
  cout << 0 << endl;
  return 0;
}
