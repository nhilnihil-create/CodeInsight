#include<iostream>
#include<string>
using namespace std;
int main(){
  string s;
  cin>>s;
  int sum = 0;
  for(int i=0; s[i]; i++){
    if(s[i]=='+') sum++;
    else sum--;
  }
  cout<<sum;
}