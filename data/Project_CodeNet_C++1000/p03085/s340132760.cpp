#include<iostream>
#include<string>
using namespace std;
int main()
{
  string b;
  cin>>b;
  if(b=="A"){
    cout<<"T";
  }
  else if(b=="T"){
    cout<<"A";
  }
  else if(b=="G"){
    cout<<"C";
  }
  else if(b=="C"){
    cout<<"G";
  }
}