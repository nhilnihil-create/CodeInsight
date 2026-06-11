#include <bits/stdc++.h>
using namespace std;

int main() {
  char a,b,c,d;
  cin>>a>>b>>c>>d;
  int A=a-'0', B=b-'0', C=c-'0', D=d-'0';
  string ansab,ansbc,anscd;
  
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      for(int k=0;k<2;k++){
        int seven=A;
        
        if(i==0)
          seven+=B;
        else
          seven-=B;
        
        if(j==0)
          seven+=C;
        else
          seven-=C;

        if(k==0)
          seven+=D;
        else
          seven-=D;
        
        if(seven==7){
          ansab = i==0 ? "+":"-";
          ansbc = j==0 ? "+":"-";
          anscd = k==0 ? "+":"-";
        }
      }
    }
  }
  cout<<a+ansab+b+ansbc+c+anscd+d<<"=7"<<endl;
}
