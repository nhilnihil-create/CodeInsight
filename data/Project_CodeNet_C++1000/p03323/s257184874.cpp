#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   int a,b;
   cin>>a>>b;
   if(a==b || abs(a-b)==1 || abs(b-a)==1){
      cout<<"Yay!"<<endl;
   }
   else{
      cout<<":("<<endl;
   }
   }