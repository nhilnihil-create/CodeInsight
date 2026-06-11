#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   string S;
   cin>>S;
   bool a=false,b=false,c=false;
   
   rep(i,3){
       if(S[i]=='a') a=true;
       if(S[i]=='b') b=true;
       if(S[i]=='c') c=true;
   }
   if(a==true&&b==true&&c==true){
       cout<<"Yes"<<endl;
   }
   else{
       cout<<"No"<<endl;
   }
}