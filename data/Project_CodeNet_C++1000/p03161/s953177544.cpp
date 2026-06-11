#include<bits/stdc++.h>
using namespace std;

int mat[100003] , minn = INT_MAX;

int solve(int arr[] , int pos ,int k){
	
	if(pos==0){
		return 0;
	}
	else{
	if(mat[pos]!=-1){
		return mat[pos];
	}	
	for(int r = 1; r<=k ;r++){
		
		int returnValue ;
		if(pos-r>=0){
			 returnValue = solve(arr , pos-r , k) + abs(arr[pos] - arr[pos-r]);	
		}

		if( returnValue < minn ){
			minn = returnValue;
		}
	}
	mat[pos] = minn;
	minn = INT_MAX;
	return mat[pos];
	}
}

int main()
{


memset( mat , -1 ,  sizeof(mat) );
int n ,k;
cin>>n>>k;

int arr[n] , i;

for(i=0;i<n;i++){
	cin>>arr[i];
}
int size = sizeof(arr)/sizeof(int); 

cout<<solve(arr , size-1 , k );

   return 0;
}
