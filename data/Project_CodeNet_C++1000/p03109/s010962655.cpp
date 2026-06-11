#include<bits/stdc++.h>
using namespace std;


int main(){

string c;
cin>>c;
int a=c[0]-48;
int b=c[3]-48;
int d=c[5]-48;
int e=c[6]-48;
if(a<=2&&b<=9){
  if(d==0&&e<=4){
    cout<<"Heisei"<<endl;
  }
  else{
    cout<<"TBD"<<endl;
  }

}
else{
  cout<<"TBD"<<endl;
}



return 0;}
