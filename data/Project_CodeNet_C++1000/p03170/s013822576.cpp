//#define sort(nums) sort(nums.begin(),nums.end())
#include <bits/stdc++.h>
#define mod 1000000007
#define deb(x) cout<<#x<<" "<<x<<endl
using namespace std;
using ll = long long int;

void jets(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

string solve(std::vector<int>& stones,int k){
	int n=stones.size();
	bool dp[k+1]={0};
	for(int i=1;i<=k;i++){
		for(int move : stones){
			if(move<=i){
				if(dp[i-move]==0)
					dp[i]=1;
			}
		}
	}
	return dp[k] ? "First" : "Second"; 
}


int main(){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    jets();
    int n,k;
    cin>>n>>k;
    vector<int> stones(n);
    for(int i=0;i<n;i++)
    	cin>>stones[i];
    bool flag=1;
    cout<<solve(stones,k);


    return 0;
}