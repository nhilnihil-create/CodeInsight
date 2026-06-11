#include<bits/stdc++.h>

using namespace std;


long long int minimumposiblecost(long long int *arr,int n){


    long long int DP[n][n];

     long long int prefix_sum[n];

     long long int sum=0;

     for(int i=0;i<n;i++)
     {
     	sum+=arr[i];
     	prefix_sum[i]=sum;
     }

 
  for(int i=0;i<n;i++)
  	DP[i][i]=0;


  for(int len=1;len<n;len++){

  
    for(int i=0,j=len;j<n;j++,i++){

        if(len==1)
        DP[i][j]=arr[i]+arr[j];
    
      else{
              long long int ans=10000000000000000;
          for(int k=i;k<j;k++)
           {
              long long int pre1=(i==0)?prefix_sum[k]:(prefix_sum[k]-prefix_sum[i-1]);
               long long int pre2=prefix_sum[j]-prefix_sum[k];
              
            ans=min(ans,pre1+pre2+DP[i][k]+DP[k+1][j]);

           }
              
              DP[i][j]=ans;

      }


    }



  }


return DP[0][n-1];

}



int main(){

    int n;
    cin>>n;


    long long int arr[n];
    
 
     for(int i=0;i<n;i++)
     	cin>>arr[i];


     cout<<minimumposiblecost(arr,n)<<endl;


	return 0;
}