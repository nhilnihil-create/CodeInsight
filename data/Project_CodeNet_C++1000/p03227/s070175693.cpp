#include<bits/stdc++.h>
using namespace std;

int main(void){
   string S;
   cin>>S;
   if(S.size()==2){
      cout<<S<<endl;
   }else{
      reverse(S.begin(),S.end());
      cout<<S<<endl;
   }
   return 0;
}
