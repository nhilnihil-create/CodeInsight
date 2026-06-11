#include"bits/stdc++.h"
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define bug( x ) cerr << #x << '=' << x << '\n' ;


int n , m , c;



int main(){

	IOS

	cin >> n >> m >> c ;

	int B[m] , A[n][m];

	for (int i = 0; i < m; ++i)
	{
		cin >> B[i] ;
	}

	int calculate = 0 , cnt = 0;

	for (int i = 0; i < n; ++i)
	{
		for(int j=0 ; j<m ; j++){

			cin >> A[i][j];

			calculate += (A[i][j] * B[j]) ;
		}

		if(calculate + c > 0)cnt++;

		calculate = 0 ;
	}

	cout << cnt << '\n';


}