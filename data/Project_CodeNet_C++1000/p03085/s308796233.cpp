#include "iostream"
using namespace std;
int main(){
  string a[4]={"A","C","G","T"};
  string b[4]={"T","G","C","A"};
  string c;
  cin>>c;
  for(int i=0;i<4;i++){
    if(a[i]==c){
      cout<<b[i]<<endl;
      break;
    }
  }
}
