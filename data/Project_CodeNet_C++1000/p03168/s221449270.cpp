#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define sorted(a_1) sort(a_1.begin(),a_1.end())
#define rsorted(a_1) sort(a_1.rbegin(),a_1.rend())
#define t1(a_1) cout<<a_1<<endl;
#define t2(a_1) for(auto it_test : a_1) cout<<it_test<<" ";
#define MOD 1000000007

long double dp[3001][3001];
long double probability(vector<double>&arr, int index, int tail){
	if(index<0 || tail<0){ return 1.0;}
	if(dp[tail][index]>0.0) return dp[tail][index];
	if(tail==0){
		dp[tail][index]=arr[index]*probability(arr,index-1,tail);
		return dp[tail][index];
	}
	else{
		dp[tail][index]=(1-arr[index])*probability(arr,index-1,tail-1)+arr[index]*probability(arr,index-1,tail);
		return dp[tail][index];
	}
}
void solve(){
    int n;
    cin>>n;
    vector<double>arr(n);
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    memset(dp,0,sizeof(dp));

    //top down
  	// long double ans = probability(arr,n-1,(n%2==0)?n/2-1:n/2);

  	//Bottom up
  	
  	for(int i=0;i<=((n%2==0)?n/2-1:n/2) + 1;i++){
  		for(int j=0;j<=n;j++){
  			if(i==0 || j==0) dp[i][j]=1.0;
  			else if(i==1){
  				dp[i][j] = arr[j-1]*dp[i][j-1];
  			}
  			else{
  				dp[i][j] = (1-arr[j-1])*dp[i-1][j-1] + arr[j-1]*dp[i][j-1];
  			}
  		}
  	}
  	cout<<fixed<<setprecision(10)<<dp[((n%2==0)?n/2-1:n/2) + 1][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--){
        solve();
    }

return 0;
}