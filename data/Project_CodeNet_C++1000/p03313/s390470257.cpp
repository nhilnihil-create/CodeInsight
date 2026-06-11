#include<bits/stdc++.h>

#define I inline void 

using namespace std ; 

using ld = long double ; 
using ll = long long ; 

const int N = 1e6  + 7 , mod = 1e9 + 7 ; 

int n;   

ll masks[N][2] ; 

I maint(int ix , int v){
	if(v > masks[ix][0]){
		swap(masks[ix][1] , masks[ix][0]) ; 
		masks[ix][0] = v ; 
	}
	else if(v > masks[ix][1]){
		masks[ix][1] = v ; 
	}
}

int main(){
	ios_base::sync_with_stdio(0) ; 
	cin.tie(0) ; 

	//freopen("in.in"  ,"r" , stdin) ; 

	cin >> n; 
	for(int i = 0 ;i <  (1 << n ) ; i++){
		cin >> masks[i][0] ; 
	}
	for(int j = 0 ;j < n ;j++){
		for(int i = 0 ;i < (1<< n ) ; i++){
			if(i&(1<<j)){
				int in = i ^ (1<<j) ; 
				maint(i , masks[in][0]) ; 
				maint(i , masks[in][1]) ; 
			}

		}
	}
	ll msk = 0 ; 
	for(int i =1 ; i< (1<<n) ;i++){
		msk = max(msk , masks[i][0] + masks[i][1]) ; 
		cout<< msk<<"\n" ; 
	}

	return 0 ; 
}