#include <bits/stdc++.h>
using namespace std;
 
 string arr;
long long  int dp[18][180][2];
int maxs; 
 
 
long long int back(int in, long long int sum, bool flag  ){
 	if(in> arr.size()) {  if(sum>maxs) maxs = sum;  return sum;  }
 	
 	if(dp[in][sum][flag]!=-1) return dp[in][sum][flag];
 	
 	 int limit = 9;
 	 if(!flag) limit=  arr[in-1]-'0';
 	
 	int res=0;
 	for(int i=0; i<=limit; ++i){
 		res+= back(in+1, sum+i, flag || i<limit);		
 	}
 	return dp[in][sum][flag]=  res;
 	
 }
 
 
 
int main() {

	long long int s1;
	
	string a;
	 cin>>a;
	 	maxs=-1;
		memset(dp, -1, sizeof dp);
	 	arr=a;
	 
	    s1 = back(1,0,false);
		
	 	cout<< (maxs)<<'\n';
	 	
	 
	
	return 0;
}
