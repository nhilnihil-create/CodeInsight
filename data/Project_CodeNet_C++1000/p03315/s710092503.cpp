#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int x=0;
 for(int i=0;i<4;i++){
   if(s.at(i)=='+'){
     x++;}
   else {x--;}
 }
  cout<<x<<endl;
}
