#include <bits/stdc++.h>
using namespace std;
int main(){
  int A;
  int B;
  cin>>A;
  cin>>B;
  string C;
  cin>>C;
  string D;
  D="Yes";
  
  
  if(C.at(A)!='-'){
      D="No";
  }
  if(D=="Yes"){  
    for(int i=0;i<A;i++){
      char c=C.at(i);
      if(!(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9')){
        D="No";
      break;
      }
    }
  }
  if(D=="Yes"){
    for(int i=0;i<B;i++){
      char c=C.at(i+A+1);
      if(!(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9')){
        D="No";
       
       	break;
      }
    }
  }
  cout<<D<<endl;
}
