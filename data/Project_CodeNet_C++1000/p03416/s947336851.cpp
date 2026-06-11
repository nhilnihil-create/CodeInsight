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
	int A,B;
	cin>>A>>B;
	int ans = 0;
	for(int i = A; i <= B; i++){
		if( isPalindromic(intToString(i)) == true){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
