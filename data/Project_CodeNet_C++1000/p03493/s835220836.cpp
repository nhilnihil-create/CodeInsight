#include<iostream>
#include<string>
using namespace std;
int main()
{
  string s;
  cin>>s;
  if(s=="111"){
    cout<<"3";
  }
  else if(s=="000"){
    cout<<"0";
  }
  else if(s=="100"||s=="001"||s=="010"){
    cout<<"1";
  }
  else if(s=="110"||s=="101"||s=="011"){
    cout<<"2";
  }
}
