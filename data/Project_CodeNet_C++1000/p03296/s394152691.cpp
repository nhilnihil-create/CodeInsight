#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
  int a,b[110],c;
  cin >> a;
  
  for(int i=0;i<a;i++)
    cin >> b[i];
  
  c =0;
  for(int i=1;i<a;i++){
    if(b[i] ==b[i-1]){
      b[i] = 0;
      c++;
    }
  }
  cout << c << endl;
  
  return 0;
}
  
    
