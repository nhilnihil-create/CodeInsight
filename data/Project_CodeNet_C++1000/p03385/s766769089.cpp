#include<iostream>
#include<string>
using namespace std;
int main()
{
  string s;
  cin>>s;
  if(s=="abc"||s=="acb"||s=="bac"||s=="bca"||s=="cab"||s=="cba"){
    cout<<"Yes";
  }
  else{
    cout<<"No";
  }
}