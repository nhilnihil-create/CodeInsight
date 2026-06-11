#include<bits/stdc++.h>
using namespace std;

int mat[100003];

int solve(int arr[] , int pos){
	
	if(pos==0){
		return 0;
	}
	else{
//		  p1 = 
//		  cout<<p1<<"\n";
	if(mat[pos]!=-1){
		return mat[pos];
	}

		if(pos>1){
		  return   mat[pos] =  min( solve(arr , pos-1) + abs(arr[pos] - arr[pos-1] ) ,  solve(arr , pos-2) + abs(arr[pos] - arr[pos-2] ) );	
//		  cout<<p2<<"\n";
		}
		else{
			return mat[pos] = solve(arr , pos-1) + abs(arr[pos] - arr[pos-1] ); 
		}
//		return min(p1,p2);
	}
}

int main()
{


memset( mat , -1 ,  sizeof(mat) );
int n;
cin>>n;

int arr[n] , i;

for(i=0;i<n;i++){
	cin>>arr[i];
}
int size = sizeof(arr)/sizeof(int); 

cout<<solve(arr , size-1 );

   return 0;
}
