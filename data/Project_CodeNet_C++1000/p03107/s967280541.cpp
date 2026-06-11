#include <bits/stdc++.h>
using namespace std;




int gcd(int a, int b){
  int bigger=max(a,b);
  int smaller=min(a,b);
  
  if (bigger%smaller==0){
    return smaller;
  }
  else {
    return gcd(smaller,bigger%smaller);
  }
  
}






int main(){

  string s;
  cin>>s;
  
  int ssize=int(s.size());
  
  int countzero=0;
  int countone=0;
  
  for (int i=0;i<ssize;i++){
    if (s.at(i)=='0'){
      countzero++;
    }
    else {
      countone++;
    }
  }
  
  
  cout<<2*min(countzero,countone)<<endl;
  
 
  
  
  
  

  

        
}