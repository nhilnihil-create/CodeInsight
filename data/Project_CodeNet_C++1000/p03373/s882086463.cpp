#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
int main(){
 int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
 int ans=0;
 if(a+b<2*c){
   if(x<=y)ans=(a+b)*x+b*(y-x);
   else ans=(a+b)*y+a*(x-y);  
 }
 else {
     if(x<=y){
         if(2*c>b)ans=2*c*x+b*(y-x);
         else ans=2*c*x+2*c*(y-x);
     }
     else {
         if(2*c>a)ans=2*c*y+a*(x-y);
         else ans=2*c*y+2*c*(x-y);
     }
 }
 cout<<ans<<endl;
}