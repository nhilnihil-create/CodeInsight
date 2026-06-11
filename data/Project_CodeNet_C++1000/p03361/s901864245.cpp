#include<bits/stdc++.h>
using namespace std;

int main(void){
   int H,W;
   cin>>H>>W;
   vector<vector<char>> s(H,vector<char>(W));
   for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
         cin>>s[i][j];
      }
   }
   bool ans=true;
   for(int i=1;i<H-1;i++){
      for(int j=1;j<W-1;j++){
         if(s[i][j]=='#'){
            if(s[i-1][j]!='#'&&s[i+1][j]!='#'&&s[i][j-1]!='#'&&s[i][j+1]!='#'){
               ans=false;
               break;
            }
         }
      }
   }
   if(ans) cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
   return 0;
}

