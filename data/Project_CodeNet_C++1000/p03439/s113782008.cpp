#include <iostream>
#include <string>
using namespace std ;

string s ;

void get(){ cin >> s ;}
void out(int n){ cout << n << '\n' << flush ;}

int main(){
	int n ; cin >> n ;
	out(0) ; get() ;
	if(s=="Vacant") return 0 ;
	string first = s ;
	int l,r,m ;
	l = 0 ;
	r = n-1 ;
	while(l+1<r){
		m = (l+r)/2 ;
		out(m) ; get() ;
		if(s=="Vacant") return 0 ;
		if(m&1){
			if(first==s) r = m ;
			else l = m ;
		}else{
			if(first!=s) r = m ;
			else l = m ;
		}
	}
	out(r) ; get() ;
	if(s=="Vacant") return 0 ;
}
