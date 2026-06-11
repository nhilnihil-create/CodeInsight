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


 //ll  a,b,c,s,t,i,j,k,x,y,z;
 //ll A,B,C,S,T,X,Y,Z;
 ll count;
signed main(){
	int N;

	cin>>  N  ;
	vector <int> X(N);
	vector <int> Y(N);
	vector <int> t(N);
  
  REP(i,N) cin>>  t[i]  >>  X[i]  >>  Y[i]  ;
bool wo = false;
  REP(i,N){
  	wo = true;
  	if(i==0){
  		REP(j,t[i]/2+1){
  			if(X[0]+Y[0]==t[0]-j*2) {
  				wo = false;
  				break;
  		}
  	}
  }
  	else {
  		REP(j,t[i]/2+1){
  		if(abs(X[i]-X[i-1])+abs(Y[i]-Y[i-1])==t[i]-t[i-1]-j*2){
  			wo = false;
  			break;
  		}
  	}
  }
  		if(wo){
  			cout<< "No";
  			return 0;
  		}
  
  }

 cout<<  "Yes"  <<endl;
  
 return 0;
}
