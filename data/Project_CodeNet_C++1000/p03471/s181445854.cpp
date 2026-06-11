#include<bits/stdc++.h>

typedef  long long ll;
//forループ
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
//
//
#define int long long

using namespace std;

int ctoi(char c) {
 switch (c) {
 case '0': return 0;
 case '1': return 1;
 case '2': return 2;
 case '3': return 3;
 case '4': return 4;
 case '5': return 5;
 case '6': return 6;
 case '7': return 7;
 case '8': return 8;
 case '9': return 9;
 default: return 0;
 }
}


 ll  a,b,c,i,j,k,x,y,z;
 ll A,B,C,X,Y,Z;
 ll count;
signed main(){

 cin >>  a  >>  b  ;
  
  REP(i,a+1)REP(j,a+1-i){
  	if(10000*i+5000*j+1000*(a-i-j)==b){

  		cout<<  i  <<" "<<  j  <<" "<<  a-i-j;
  
 return 0;
  	}
  }
 cout<<  -1  <<" "<<  -1 <<" "<<  -1  <<endl;
  
 return 0;
}
