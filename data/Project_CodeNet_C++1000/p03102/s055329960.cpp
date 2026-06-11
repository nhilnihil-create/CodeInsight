#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;
const ll modP = 1000000007;


int main()
{
	int n,m,c;
	cin>>n>>m>>c;
	vector<int> B(m);
	rep(i,m) cin>>B[i];
	vector<vector<int>> A = vector<vector<int>>(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int num;
			cin>>num;
			A[i].push_back(num);
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		ll sum = 0;
		for(int j = 0; j < m; j++){
			sum += A[i][j] * B[j];
		}
		if( sum + c > 0) ans++;
	}
	
	cout<<ans<<endl;
	return 0;
}
