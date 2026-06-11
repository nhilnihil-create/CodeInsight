#include<iostream>
#include<string>
using namespace std;
int main(){
  int n,i,ans = 0;string a,b,c;cin >> n >> a >> b >> c;
  for(i=0;i<n;i++){
    if(a[i]!=b[i] && b[i]!=c[i] && a[i]!=c[i]) ans += 2;
    else if(!(a[i]==b[i] && b[i]==c[i])) ans += 1;
  }
  cout << ans << endl;
}
