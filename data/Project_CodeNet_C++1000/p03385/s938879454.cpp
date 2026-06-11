#include "iostream"
#include "string"
using namespace std;
int main(){
  string a;
  int b=0,c=0,d=0;
  cin>>a;
  for(int i=0;i<3;i++){
    if(a[i]=='a'){
      b++;
    }
    else if(a[i]=='b'){
      d++;
    }
    else{
      c++;
    }

  }

  if((b==1)&&(c==1)&&(d==1)){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
