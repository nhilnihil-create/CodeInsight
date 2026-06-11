#include "iostream"
#include "string"
using namespace std;
int main(){
  string a;
  cin>>a;
  int d=700;
  for(int i=0;i<3;i++){
    if(a[i]=='o'){
      d+=100;
    }
  }
  cout<<d<<endl;
}
