/*
Created on Fri Aug 25 16:34:06 2020

@author: roastedcoder

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long int ull;
const int mod = 1e9+7;
#define endl "\n"
#define append push_back
#define roastedcoder ios_base::sync_with_stdio(false); cin.tie(NULL);
//__________________________________________________________________

string a, b;

string weird(int n, int m) {
	int dp[n+1][m+1];
  	for(int i = 0; i<n+1; i++) {
  		for(int j = 0; j<m+1; j++) {
  			if(i == 0 || j == 0) dp[i][j] = 0;
  			
  			else if(a[i-1] == b[j-1]) dp[i][j] = 1+dp[i-1][j-1];
  			
  			else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	int i = n, j = m;
	string res = "";
	while(i>0 && j>0) {
		if(a[i-1] == b[j-1]) {
			res.append(a[i-1]);
			i--;
			j--;
		}
		else {
			if(dp[i-1][j] < dp[i][j-1]) {
				j--;
			}
			else i--;
		}
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	roastedcoder
	cin>>a>>b;
  	int n = a.length(), m = b.length();
	cout<<weird(n, m);
}

//__________________________________________________________________
/*
Sample Input:
axyb
abyxb

Sample Output:
ayb

*/