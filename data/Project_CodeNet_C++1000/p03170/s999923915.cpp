#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
  cin>>n>>k;
  bool* dp=new bool[k+1];
  int* A=new int[n]; 
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  for(int i=0;i<k+1;i++){
    dp[i]=false;
  	if(i==0)
      dp[i]=false;
    else{
    	for(int j=0;j<n;j++){
          	if(i>=A[j])
        		dp[i]=dp[i]||!dp[i-A[j]];
        }
    }
  }
  if(dp[k])
    cout<<"First"<<endl;
  else
    cout<<"Second"<<endl;
}
