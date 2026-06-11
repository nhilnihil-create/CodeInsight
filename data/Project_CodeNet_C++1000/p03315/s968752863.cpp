#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   string S;
   cin>>S;
   int ans=0;
   rep(i,4){
       if(S[i]=='+'){
           ans++;
       }
       else{
           ans--;
       }
   }
   
    cout<<ans<<endl;
}