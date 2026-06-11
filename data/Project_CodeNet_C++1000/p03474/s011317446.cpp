#include <iostream>
#include<cmath>
using namespace std;
#define ll long long
#define ld long double

int main(void){
  int a,b;
  string s;
  
  cin>>a>>b;
  cin>>s;
  if(s[a]!='-'){
      cout<<"No";
      return 0;
  }

  for(int i=0;i<s.length();i++){
      if(i!=a && (s[i]>'9' || s[i]<'0')){
          cout<<"No";
          return 0;
      }
  }
  
  cout<<"Yes";
    
}
