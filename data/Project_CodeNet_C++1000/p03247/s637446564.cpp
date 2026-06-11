#include<bits/stdc++.h>
#define IL inline
#define _ 1005
#define ll long long
using namespace std ;

IL ll gi(){
	ll data = 0 , m = 1; char ch = 0;
	while(ch!='-' && (ch<'0'||ch>'9')) ch = getchar();
	if(ch == '-'){m = 0 ; ch = getchar() ; }
	while(ch >= '0' && ch <= '9'){data = (data<<1) + (data<<3) + (ch^48) ; ch = getchar(); }
	return (m) ? data : -data ; 
}

ll X[_],Y[_],dis[_],n,m,mx[_],my[_] ;
vector<ll>Arm ;
vector<char>Ans[_] ;

namespace cpp300{
	IL void main() {		
		if(!(dis[1]&1)) {
			m = 40 ;
			cout << m << endl ;
			for(int i = 1; i <= m; i ++) putchar('1'),putchar(' ') ; puts("") ;
			for(int i = 1,stp = 0; i <= n; i ++) {
				stp = m ; 
				if(X[i] < 0) while(X[i] != 0) putchar('L') , X[i] ++ , -- stp ;
				if(X[i] > 0) while(X[i] != 0) putchar('R') , X[i] -- , -- stp ;
				if(Y[i] < 0) while(Y[i] != 0) putchar('D') , Y[i] ++ , -- stp ;
				if(Y[i] > 0) while(Y[i] != 0) putchar('U') , Y[i] -- , -- stp ;
				for(int j = 1; j <= stp / 2; j ++) putchar('U') , putchar('D') ;
				puts("") ;
			}
		}
		else if(dis[1] & 1) {
			m = 39 ;
			cout << m << endl ; 
			for(int i = 1; i <= m; i ++) putchar('1'),putchar(' ') ; puts("") ;
			for(int i = 1,stp = 0; i <= n; i ++) {
				stp = m ; 
				if(X[i] < 0) while(X[i] != 0) putchar('L') , X[i] ++ , -- stp ;
				if(X[i] > 0) while(X[i] != 0) putchar('R') , X[i] -- , -- stp ;
				if(Y[i] < 0) while(Y[i] != 0) putchar('D') , Y[i] ++ , -- stp ;
				if(Y[i] > 0) while(Y[i] != 0) putchar('U') , Y[i] -- , -- stp ;
				for(int j = 1; j <= stp / 2; j ++) putchar('U') , putchar('D') ;
				puts("") ;
			}
		}
		return ; 
	}
}

namespace cpp600{
	IL void main() {
		m = 0 ; 
		if(dis[1] % 2 == 0) {
			for(int i = 1; i <= n; i ++) {
				Ans[i].push_back('R') ; X[i] -- ; 				
			}
			m ++ ; Arm.push_back(1) ;
		}
		for(int i = 1; i <= n; i ++) X[i] = 2ll * X[i] , Y[i] = 2ll * Y[i] ;
		for(int i = 1; i <= n; i ++) {
			ll x = X[i] , y = Y[i] ;
			X[i] = x + y ; Y[i] = x - y ;
			X[i] >>= 1 ; Y[i] >>= 1 ; 
		}
		//for(int i = 1; i <= n; i ++) cout << X[i] << " " << Y[i] << endl ;
		m += 34 ;
		for(int i = 1; i <= 34; i ++) Arm.push_back(1ll << (i - 1)) ;
		for(int i = 1; i <= n; i ++) {
			for(int e = 0; e <= 33; e ++) mx[e] = my[e] = 0 ;
			for(int e = 33; e >= 0 ; e --) {
				if(X[i] <= 0) mx[e] = 1 , X[i] += (1ll<<e) ;
				else if(X[i] > 0) mx[e] = -1 , X[i] -= (1ll<<e) ;
			}
			for(int e = 33; e >= 0 ; e --)
				if(Y[i] <= 0) my[e] = 1 , Y[i] += (1ll<<e) ;
				else if(Y[i] > 0) my[e] = -1 , Y[i] -= (1ll<<e) ; 
			for(int e = 0; e <= 33; e ++)
				if(mx[e] > 0 && my[e] > 0) Ans[i].push_back('L') ;
				else if(mx[e] < 0 && my[e] < 0) Ans[i].push_back('R') ;
				else if(mx[e] > 0 && my[e] < 0) Ans[i].push_back('D') ;
				else if(mx[e] < 0 && my[e] > 0) Ans[i].push_back('U') ;
		}
		cout << m << endl ;
		for(int i = 0; i < m; i ++) cout << Arm[i] << " " ;cout << endl ;
		for(int i = 1; i <= n; i ++) {
			for(int j = 0; j < m; j ++) cout << Ans[i][j] ;
			cout << endl ;
		}
		return ;
	}
}

int main() {
	n = gi() ;
	bool flag = true ; 
	for(int i = 1; i <= n; i ++) {
		X[i] = gi() , Y[i] = gi() ;
		if(!(-10 <= X[i] && X[i] <= 10)) flag = false ;		
		if(!(-10 <= Y[i] && Y[i] <= 10)) flag = false ; 
	}
	for(int i = 1; i <= n; i ++) dis[i] = abs(X[i]) + abs(Y[i]) ;
	for(int i = 2; i <= n; i ++) if((dis[i]&1) != (dis[1]&1)) {puts("-1") ; return 0 ;}
	//if(flag) cpp300::main() ;
	/*else*/ cpp600::main() ; 
	return 0 ; 
}
