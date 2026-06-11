#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int findSumOfDigits(int n){
	int sum = 0;
	while(n > 0){
		sum += n%10;
		n /= 10;
	}
	return sum;
}
int main(){
	int n;
	cin >> n;
	int minimum = 1e6;
	for(int i = 1; i<n; i++){
		int sum = findSumOfDigits(i) + findSumOfDigits(n-i);
		minimum = min(sum,minimum);
	}
cout << minimum << endl;
}