#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int n,m ;
	cin>>n>>m ;

	int l=1 ;
	int r=n ;	

	rep(i,m){
		int x,y ;
		cin>>x>>y ;
		l=max(l,x) ;
		r=min(r,y) ;
 	}	

 	int count=0 ;
 	for(int i=l;i<=r;i++)
 	{
 		count++ ;
 	}

 	cout<<count ;
}



int main(){

	int y ;

	y=1 ;
	//cin>>y ;

	while(y--)
	{	
		solve() ;
	}

}
