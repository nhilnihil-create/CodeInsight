#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int solve(vector<int> A){
	int ans;
	if((A[1]-A[0])%2==0) {
		ans = (A[1]-A[0])/2 + A[2]-A[1];
	}
	else{
		ans = (A[1]-A[0])/2 + A[2]-A[1] + 2;
	}

	return ans;
}	


int main(){
	vector<int> N(3);
	cin >> N[0] >> N[1] >> N[2];
	sort(N.begin(),N.end());
	cout << solve(N) << endl;
}












