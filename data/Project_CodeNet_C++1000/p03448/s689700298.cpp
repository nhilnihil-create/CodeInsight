#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,X;
  cin>>A>>B>>C>>X;
  int Ans=0;
  int limA,limB,limC;
  limA=min(X/500,A);
  if(X%50==0){
    for(int i=0;i<limA+1;i++){
        limB=min((X-500*i)/100,B);
        for(int j=0;j<limB+1;j++){
            if((X-500*i-100*j)/50<=C){
                Ans++;
            }
        }
    }
  }
    cout<<Ans<<endl;
    

}