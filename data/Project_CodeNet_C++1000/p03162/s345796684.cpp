#include<bits/stdc++.h>
using namespace std;

int mat[100001][3];
int solve(int arr[][3] , int size , int col){
	if(size==0){
		return arr[0][col];
	}
	if(mat[size][col]!=-1){
		return mat[size][col];
	}
	if(col==0){
//		cout<<col<<"\n";
//		cout<<solve(arr,size-1,1)+arr[size][col]<<"   ";
//		cout<<solve(arr,size-1,2)+arr[size][col]<<"\n";
	return mat[size][col]  = max( solve(arr,size-1,1)+arr[size][col] , solve(arr,size-1,2)+arr[size][col]  );	
	}
	else if(col==1){
//		cout<<col<<"\n";
//		cout<<solve(arr,size-1,0)+arr[size][col]<<"   ";
//		cout<<solve(arr,size-1,2)+arr[size][col]<<"\n";
		return mat[size][col] =  max( solve(arr,size-1,0)+arr[size][col] , solve(arr,size-1,2)+arr[size][col]  );	
	}
	else if(col==2){
//		cout<<col<<"\n";
//		cout<<solve(arr,size-1,0)+arr[size][col]<<"   ";
//		cout<<solve(arr,size-1,1)+arr[size][col]<<"\n";
		return mat[size][col]  = max( solve(arr,size-1,0)+arr[size][col] , solve(arr,size-1,1)+arr[size][col]  );	
	}
}
int main()
{

memset(mat, -1 ,sizeof(mat));

int n;
cin>>n;
int arr[n][3] ,size;
for(int i=0;i<n;i++){
	cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
}
int col = 0;
int s1 ,s2 ,s3 ;

s1 = solve(arr , n-1 ,0 );
s2 = solve(arr , n-1 ,1 );
s3 = solve(arr , n-1 ,2 );

//cout<<s1<<" "<<s2<<" "<<s3;

cout<<max( max(s1,s2) , s3);
	
   return 0;
}
