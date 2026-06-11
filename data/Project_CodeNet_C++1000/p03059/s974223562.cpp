#include <iostream> 
using namespace std;
int main(){
  int a,b,c;cin>>a>>b>>c;
  int i = 1;
  int z = 0;
  while(a*i <= c){
    z += b;
    i++;
  }
  cout << z << endl;
}
