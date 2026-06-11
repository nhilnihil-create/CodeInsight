#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int n;
  cin >> n;
  string str;
  
  if(n==0){
    cout << 0 << endl;
    return 0;
  }
  
  int i=0;
  long int tmp = 1;
  while(n!=0){
    tmp = tmp * (-2);
    //cout << "tmp = " << tmp << endl;
    if(n%tmp != 0){
      str = "1" + str;
      n = n - (tmp/(-2));
    } else {
      str = "0" + str;
    }
    
    i++;
  }
  
  cout << str << endl;

  return 0;
}