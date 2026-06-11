#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   string S;
   cin>>S;
   int fee=700;
   rep(i,3){
       if(S[i]=='o'){
           fee+=100;
       }
   }
   cout<<fee<<endl;
}