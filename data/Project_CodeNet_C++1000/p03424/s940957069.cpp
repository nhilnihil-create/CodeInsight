#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin>>N;
  int sum=0;
  for(int i=0;i<N;i++){
    char A;
    cin>>A;
    char c='Y';
    if(A==c){
      cout<<"Four"<<endl;
      sum=1;
      break;
    }
  }
   if(sum!=1){
     cout<<"Three"<<endl;
   }


}
