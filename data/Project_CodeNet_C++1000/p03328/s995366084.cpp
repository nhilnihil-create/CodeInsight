#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int a,b;
   cin>>a>>b;
   int h=b-a;
   int T=0,ans;
   rep(i,h){
       T+=i+1;
   }
   ans=T-b;
   cout<<ans<<endl;
}