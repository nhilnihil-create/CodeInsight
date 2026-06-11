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


 long long a,b,c,s,t,x,y,z;
 long long A,B,C,S,T,X,Y,Z;

 long long cnt;

 long double pi=3.14159265358979323846;

 string N,M;

unsigned long long D;

//long long mam(long long a, long long b){}

int main(){

	cin>>a;

	if(0<a%100 && a%100<13 && 0<a/100 && a/100<13) cout<<"AMBIGUOUS";
	else{
		if(0<a%100 && a%100<13) cout<<"YYMM";
		else{
			if(0<a/100 && a/100<13) cout<<"MMYY";
			else cout<<"NA";
		}}

	return 0;

}
