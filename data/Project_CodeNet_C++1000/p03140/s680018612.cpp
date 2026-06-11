#include <iostream>
#include <string>
using namespace std;
int main(void){
  int N;
  cin >> N;
  
  string a,b,c;
  cin >> a >> b >> c;
  
  int ans = 0;
  
  for(int i=0;i<N;i++){
    if(a[i] == b[i] && a[i] == c[i]);
    else if(a[i] == b[i] || a[i] == c[i] || b[i] == c[i])
      ans++;
    else
      ans += 2;
  }
  
  cout << ans << endl;
  
  return 0;
}

  
