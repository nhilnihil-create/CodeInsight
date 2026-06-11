#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   string n;
   cin>>n;
   rep(i,3){
       if(n[i]=='1'){
           n[i]='9';
       }
       else if(n[i]=='9'){
           n[i]='1';
       }
       cout<<n[i];
   }
    cout<<endl;
}