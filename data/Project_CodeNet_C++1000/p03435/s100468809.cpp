#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define all(v) v.begin(), v.end()

int main() {
  int c,d,e,f,g,h,i,j,k;
bool ans=false; 
 cin>>c>>d>>e>>f>>g>>h>>i>>j>>k;
  for(int a1=-100;a1<=100;a1++){
    for(int a2=-100;a2<=100;a2++){
       for(int a3=-100;a3<=100;a3++){
     int b1=c-a1;
     int b2=d-a1;
     int b3=e-a1;
         if(f==a2+b1&&g==a2+b2&&h==a2+b3&&i==a3+b1&&j==a3+b2&&k==a3+b3){
         ans=true;}
   }
   }
  }
  if(ans){
cout<<"Yes"<<endl;
}else{
 cout<<"No"<<endl; }
}
