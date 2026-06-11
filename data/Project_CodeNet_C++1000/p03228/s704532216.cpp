#include <iostream>
using namespace std;

int main(){
  int a,b,n;
  cin >> a >> b >> n;
  for(int i=0;i<n;i++){
    if(i%2==0){
      a=a/2;
      b+=a;
    }
    else{
      b/=2;
      a+=b;
    }
  }
  cout << a << " " << b << endl;
}