#include <iostream>
using namespace std;
int main(){
  int n; cin >> n;
  int p=0;
  
  for(int i=1;i<=n;i+=2){
    int o=0; 
    for(int j=1;j<=i;j++)
        if(i%j==0) o++;
    if(o==8)p++;
  }
  
  cout << p << endl;

  return 0;
}