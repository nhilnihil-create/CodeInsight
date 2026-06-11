#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//累積和で→Eの数をカウント
int main() {
   int n;
   string s;
   cin>>n>>s;
   vector<int> rui(n);
   if(s[0]=='E')rui[0]=1;
   rep(i,n-1){
       if(s[i+1]=='E')rui[i+1]=rui[i]+1;
       else rui[i+1]=rui[i];
   }
   
   int ans=n+1;
   rep(i,n){
       if(s[i]=='E'){
           ans=min(ans,i-(rui[i]-1)+(rui[n-1]-rui[i]));
       }
       else{
           ans=min(ans,i-rui[i]+(rui[n-1]-rui[i]));
       }
   }
   cout<<ans<<endl;
}