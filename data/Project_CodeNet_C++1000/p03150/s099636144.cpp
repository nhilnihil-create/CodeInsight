#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	string s ;
	cin>>s ;

	if(s=="keyence"){
		cout<<"YES" ;
		return ;
	}

	int n=s.length() ;

	for(int i=0;i<n;i++){
		
		for(int j=i;j<n;j++){
		
			string x="" ;

			for(int k=0;k<n;k++){

				if(k>=i && k<=j){
					continue ;
				}
				else{
					x.push_back(s[k]) ;
				}

			}

			if(x=="keyence"){
				cout<<"YES" ;
				return ;
			}

			//cout<<x<<"\n" ;
		}
	}

	cout<<"NO" ;

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