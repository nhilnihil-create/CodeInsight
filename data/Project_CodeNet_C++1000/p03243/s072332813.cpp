#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0 ; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007;

bool issame(int n){

	string s=to_string(n) ;
 	char temp=s[0] ;

 	rep(i,(int)s.length()){
 		if(s[i]!=temp)
 			return false ;
 	}

 	return true ;
}

void solve(){

	int n ;
	cin>>n ;

	while(n<=1111){

		bool answer=issame(n) ;
	
		if(answer==true){
			break ;
		}
	
		n++ ;
		
		//cout<<n<<"\n" ;

	}

	cout<<n ;
	
}


int main(){

		int y ;

		y=1 ;
		//cin>>y ;

		while(y--){
 
			solve() ;

		}

}