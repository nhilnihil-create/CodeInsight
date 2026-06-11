#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  char a[100],b[100],c[100];
  for(int i=0; i!=n; i++){
    cin >> a[i];
  }
  for(int i=0; i!=n; i++){
    cin >> b[i];
  }
  for(int i=0; i!=n; i++){
    cin >> c[i];
  }
  int ans = 0;
  for(int i=0; i!=n; i++){
    if(a[i] == b[i] && b[i] == c[i]){
      continue;
    }
    if(a[i] != b[i] && b[i] != c[i] && a[i] != c[i]){
      ans += 2;
      continue;
    }
    ans += 1;
  }
  cout << ans << '\n';
  return 0;
}
