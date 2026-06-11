#include <bits/stdc++.h>
using namespace std;
 int main(){
 string a;
 cin >>a;
 int c=700;
   for(int i=0;i<3;i++){
   if(a.at(i)=='o'){
     c+=100;
   }
   }
   cout <<c<<endl;
 }