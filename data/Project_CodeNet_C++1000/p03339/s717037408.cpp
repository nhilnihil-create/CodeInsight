#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
 int N;
 cin>>N;
 string S;
 cin>>S;
 int cnt=0;
 rep(i,S.size()){
     if(i!=0){
         if(S[i]=='W'){
         }
         else{
             cnt++;
         }
     }
 }
 int ans=cnt;
 rrep(i,S.size()-1){
     if(S[i-1]=='W'){
         cnt++;
     }
     if(S[i]=='E'){
         cnt--;
     }
     if(cnt<ans){
         ans=cnt;
     }
 }
 cout<<ans<<endl;
}