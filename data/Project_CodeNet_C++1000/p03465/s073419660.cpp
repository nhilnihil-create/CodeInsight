#include<bits/stdc++.h>
using namespace std;
const int N=1000002;
#define all(a) a.begin(),a.end()
bitset<4000000>dp;
 
void solve(int n){
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	dp[0]=true;
	for(int i=0;i<n;i++){
		dp=dp|dp<<a[i];
	}
	long long  tot=accumulate(all(a),0ll);
	if(tot%2){
		tot++;
	}
	tot/=2;
	for(int i=tot;i<=4000000;i++){
		if(dp[i]){
			cout<<i<<' ';
			return;
		}
	}
}
int main(){
int n;
cin>>n;
solve(n);
}