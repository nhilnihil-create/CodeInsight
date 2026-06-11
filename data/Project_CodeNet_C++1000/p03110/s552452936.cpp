#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
#define swap(a,b,type)do{type temp; temp= a;a = b; b= temp;}while(0); 
int main(){
 int a;
 cin >> a;
 float c = 380000.0;
 float d = 0;
 vector< pair< float,string> >b(a);
 rep(i,a){
     cin >> b[i].first >> b[i].second ;
 }
 rep(i,a){
     if(b[i].second=="BTC"){
       d += c*b[i].first;
     }else{
         d+=b[i].first;
     }
 }
 cout << d<< endl;

 return 0; 
}