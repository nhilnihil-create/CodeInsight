#include <iostream>
using namespace std;
int main(void){
  int a,b,c,d;
  a = b = c = d = 0;
  int p;
  for(int i=0;i<6;i++){
    cin >> p;
    if(p == 1) a++;
    if(p == 2) b++;
    if(p == 3) c++;
    if(p == 4) d++;
  }
  
  if(a == 3 || b == 3 || c == 3 || d == 3) cout << "NO" << endl;
  else cout << "YES" << endl;
  
  return 0;
}
