#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){

	int a,b,c ;
	cin>>a>>b>>c ;

	priority_queue<int,vector<int>,greater<int>> q ;

	q.push(a) ;
	q.push(b) ;
	q.push(c) ;

	int prod=1 ;

	for(int i=0;i<2;i++){

		prod*=q.top() ;
		q.pop() ;

	}

	cout<<prod/2 ;

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