#include <bits/stdc++.h>
using namespace std;

int main(){
 int A,B,C,D;
  cin>>A>>B>>C>>D;
 int Left=A+B;
 int Right=C+D;
   if(Left>Right){
     cout<<"Left";
   }else if(Left<Right){
     cout<<"Right";
   }else{
     cout<<"Balanced";
   }
}