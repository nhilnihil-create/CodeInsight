#include <iostream>
#include <vector>
using namespace std;


// dp[k] : if there are k stones remaining then any person making any move wins that is dp[k - ni] is False.
// Then the person making a move on that stone wins.
int main() {
	// your code goes here
	int N=0,K=0;
	cin>>N>>K;
	vector<int> vals;
	for(int i=0;i<N;i++){
		int val = 0;
		cin>>val;
		vals.push_back(val);
	}
	vector<bool> dp(K+1, false);
	for(int i=1;i<=K;i++){
		for(int j=0;j<N && vals[j] <= i;j++){
			if(!dp[i - vals[j]]){
				dp[i] = true;
				break;
			}
		}
	}
	if(dp[K])cout<<"First"<<endl;
	else cout<<"Second"<<endl;
	return 0;
}