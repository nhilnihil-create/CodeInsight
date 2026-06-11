#include "iostream"
#include "string"
using namespace std;
int main(){
  string a;
  int b=0;
  cin>>a;
  for(int i=0;i<3;i++){
    if(a[i]=='1'){
      b++;
    }
  }


  cout<<b<<endl;
}
