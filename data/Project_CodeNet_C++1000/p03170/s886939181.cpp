#include<bits/stdc++.h>

using namespace std;

string whowillwin(int *arr,int n,int k){

 
int DP[k+1]={0};



for(int i=1;i<=k;i++){

  for(int j=0;j<n;j++){

      if(arr[j]>i)
       continue;

   else{

           if(DP[i-arr[j]]==0)
             DP[i]=1;
   }


  }




}


 return (DP[k]==0)?"Second":"First";


}


int main(){

  
   int n,k;

   cin>>n>>k;

   int arr[n];

   for(int i=0;i<n;i++)
   	 cin>>arr[i];

 cout<<whowillwin(arr,n,k)<<endl;

	return 0;
}