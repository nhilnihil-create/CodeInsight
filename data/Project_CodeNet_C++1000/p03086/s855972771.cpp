#include<bits/stdc++.h>
using namespace std;
int main(){
 string s;
 cin>>s;
 int ans=0,count=0;
 for(int i = 0; i < s.size(); i++ ){
   if(s.at(i)=='A'||s.at(i)=='C'||s.at(i)=='G'||s.at(i)=='T'){
     count++;
     ans=max(ans,count);
   }
   else{
     ans=max(ans,count);
     count=0;
   } 
 } 
 cout<<ans<<endl;
}