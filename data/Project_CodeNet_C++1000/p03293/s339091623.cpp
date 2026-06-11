#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   string S,T;
   cin>>S>>T;
   bool match=false;
   int len=S.size();
   rep(i,len){
       if(S==T){
           match=true;
           break;
       }
       S=S[len-1]+S.substr(0,len-1);
   }
    
    if(match==true){
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}