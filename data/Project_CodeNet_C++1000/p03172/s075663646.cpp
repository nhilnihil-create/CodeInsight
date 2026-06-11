

#include<bits/stdc++.h>


using namespace std;



long long int maxcandypossible(long long int *arr,int n,int k){

  long long int DP[n][k+1]; 


  for(int i=0;i<=k;i++)
    DP[0][i]=(arr[0]>=i)?1:0;


 for(int i=1;i<n;i++){

  for(int j=0;j<=k;j++)
  {

      if(j==0)
     DP[i][j]=DP[i-1][j];

   else
    DP[i][j]=(1000000007+DP[i][j-1]+DP[i-1][j]-((j-1-arr[i])>=0?DP[i-1][j-1-arr[i]]:0))%1000000007;

  }



 }



return DP[n-1][k];

}


int main(){


int n,k;

cin>>n>>k;

long long int arr[n];

for(int i=0;i<n;i++)
  cin>>arr[i];

cout<<maxcandypossible(arr,n,k)<<endl;


  return 0;
}