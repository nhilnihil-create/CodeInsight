#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0 ; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007;

void solve(){

	string s ;
	cin>>s ;
	int n=s.length() ;

	rep(i,n){
		if(s[i]=='1'){
			s[i]='9' ;
		}
		else{
			s[i]='1' ;
		}
	}
	
	cout<<s ;
}


int main(){

		int y ;

		y=1 ;
		//cin>>y ;

		while(y--){
 
			solve() ;

		}

}