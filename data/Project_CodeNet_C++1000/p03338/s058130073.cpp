#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P=pair<int,int>;
const int INF=1001001001;

int main(){
   int n; cin>>n;
   string s; cin>>s;
   int ans=0;
   for(int i=0;i<n-1;i++){
      int cnt=0;
      for(char c='a';c<='z';c++){
         bool right=false,left=false;
         for(int k=i+1;k<n;k++){
            if(s[k]==c) left=true;
            for(int j=0;j<=i;j++){
               if(s[j]==c) right=true;
            }
         }
         if(right&&left) cnt++;
      }
      ans=max(ans,cnt);
   }
   cout<<ans<<endl;
   return 0;
}
