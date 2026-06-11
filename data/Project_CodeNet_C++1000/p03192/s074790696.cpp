#include<iostream>
#include<string>

using namespace std;

int main(){
 string n;
  cin >> n;
  
 int res=0;
  if(n[0]=='2') res++;
  if(n[1]=='2') res++;
  if(n[2]=='2') res++;
  if(n[3]=='2') res++;
  
  cout << res << endl;

}