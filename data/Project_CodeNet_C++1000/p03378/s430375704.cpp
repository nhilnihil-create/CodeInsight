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

string intToString(int num){
	string str;
	while( num != 0){
		int digit = num % 10;
		num /= 10;
		str.push_back( digit);
	}
	return str;
}

bool isPalindromic(string str){
	int n = str.size();
	for(int i = 0; i < n/2; i++){
		if( str[i] != str[n-i-1]) return false;
	}
	return true;
}

int main(){
	int n,m,x;
	cin>>n>>m>>x;
	vector<int> left(n+1,0);
	vector<int> right(n+1,0);
	for(int i = 0; i < m; i++){
		int a;
		cin>>a;
		left[a] = 1;
		right[a] = 1;
	}
	for(int i = 1 ; i <= n; i++){
		left[i] = left[i] + left[i-1];
	}
	for(int i = n-1; i >= 0; i--){
		right[i] = right[i] + right[i+1];
	}
	int ans = 0;
	ans = min(left[n] - left[x],right[0] - right[x]);
	cout<<ans<<endl;
	return 0;
}
