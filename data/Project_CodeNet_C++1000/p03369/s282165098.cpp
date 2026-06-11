#include<iostream>
#include<string>
using namespace std;
int main()
{
  string s;
  cin>>s;
  if(s=="oxx"||s=="xox"||s=="xxo"){
    cout<<800;
  }
  else if(s=="oox"||s=="oxo"||s=="xoo"){
    cout<<900;
  }
  else if(s=="ooo"){
    cout<<1000;
  }
  else if(s=="xxx"){
    cout<<700;
  }
}