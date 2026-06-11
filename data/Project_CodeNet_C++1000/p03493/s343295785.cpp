#include <iostream>
#include <string>
using namespace std;

int main(){
  string a;
  cin >> a;
  int n=a.length();
  int r=0;
  char x;
  
  for(int i=0;i<n;i++){
   x=a[i];
    
    if(x=='1'){
    	r++;
    }
  }
  cout << r;
}