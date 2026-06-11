#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){

	int n ;
	cin>>n ;

	unordered_map<int,int> mp ;

	int count=1 ;

	while(true){

		//cout<<n<<" "<<count<<"\n" ;
		
		if(mp[n]==1){
			break ;
		}
		mp[n]=1 ;

		if(n%2==0){
			n=n/2 ;
		}
		else{
			n=3*n+1 ;
		}

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