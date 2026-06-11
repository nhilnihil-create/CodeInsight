#include<iostream>
using namespace std;
int main(){
char c=getchar_unlocked();
  int x=0;
  do{
  if(c=='x')x++;
  c=getchar_unlocked();
  }while(c=='o'||c=='x');
  if(x>=8)cout<<"NO\n";
  else cout<<"YES\n";
}