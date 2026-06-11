#include <bits/stdc++.h>
using namespace std;
const int INF=999999999;
char s[60][60];
int main() {
 int H,W;
 cin>>H>>W;
 for(int i=0;i<W;i++){
     for(int j=0;j<H;j++){
         cin>>s[i][j];
     }
 }

 for(int i=0;i<W;i++){
     for(int j=0;j<H;j++){
         if(s[i][j]=='#'&&s[i-1][j]!='#'&&s[i+1][j]!='#'&&s[i][j-1]!='#'&&s[i][j+1]!='#'){
             cout<<"No"<<endl;return 0;
         }
 }}
 cout<<"Yes"<<endl;
 return 0;}