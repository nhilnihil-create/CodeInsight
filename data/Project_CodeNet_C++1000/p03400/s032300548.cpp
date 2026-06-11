#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;

int main(){
	int n;
	int D,X;
	cin>>n;
	cin>>D>>X;
	vector<int> A(n);
	rep(i,n){
		cin>>A[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= D; j = j + A[i]){
			ans++;
		}
	}
	ans += X;
	cout<<ans<<endl;
	return 0;
}
