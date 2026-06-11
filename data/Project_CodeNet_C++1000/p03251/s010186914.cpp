#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int N,M,X,Y;
   cin>>N>>M>>X>>Y;
   int x,y;
   bool war=true;
   int Mx=-200,My=200;
   rep(i,N){
       cin>>x;
       Mx=max(Mx,x);
   }
   rep(i,M){
       cin>>y;
       My=min(My,y);
   }
   rep(i,Y-X){
       if(X+i+1>Mx&&X+i+1<=My){
           war=false;
       }
       }
   if(war==true){
       cout<<"War"<<endl;
   }
   else{
       cout<<"No War"<<endl;
   }
   
}