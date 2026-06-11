#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 
int main() {
int h,w;
cin>>h>>w;
 char m[66][66];
 for(int i=1;i<=h;i++){
      for(int j=1;j<=w;j++){
     cin>>m[i][j];
 }
 }
string ans ="Yes";
 for(int i=1;i<=h;i++){
      for(int j=1;j<=w;j++){
if(m[i][j]=='#' && m[i+1][j]!='#' && m[i-1][j]!='#' && m[i][j+1]!='#' && m[i][j-1]!='#')ans="No";
 }
 }
cout<<ans<<endl;
}