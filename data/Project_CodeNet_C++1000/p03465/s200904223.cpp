#include<bits/stdc++.h>
using namespace std;
bitset<2000007> dp;
int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  int sum=0;
  dp[0]=1;
  for(int i=0;i<n;i++){
  	int x;
    cin>>x;
    sum += x;
    dp = (dp|dp<<x);
  }
  int target = (sum+1)/2;
  int i;
  for( i=target;i<=sum;i++){
   	if(dp[i]){
     	break; 
    }
  }
  cout<<i;
  return 0;
}