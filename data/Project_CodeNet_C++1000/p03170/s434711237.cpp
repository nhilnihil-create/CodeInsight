#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n, k;
  	cin>>n>>k;
  	vector<int> arr(n);
  	for(int i = 0;i<n;i++){
    	cin>>arr[i];
    }
    vector<bool> dp(k+1);
   	for(int j = 0;j<k+1;j++){
		for(int i = 0;i<n;i++){
          	if(j>=arr[i])
        		dp[j] = dp[j] || !dp[j-arr[i]];
        }
      
    }
	if(dp[k]) cout<<"First"<<endl;
  	else cout<<"Second"<<endl;
}