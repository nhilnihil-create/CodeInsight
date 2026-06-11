#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	
	int arr[n];
	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}
	
	int memo[n];
	for(int i=0; i<n; i++) {
		memo[i] = INT_MAX;
	}
	memo[0] = 0;

	for(int i=1; i<n; i++) {
		for(int j=1; j<=k; j++) {
			if(i-j >= 0) {
				memo[i] = min(memo[i], abs(arr[i] -arr[i-j]) + memo[i-j]);
			} else {
				memo[i] = memo[i];
			}
		}
	}
	
	cout<<memo[n-1];
	
	return 0;
}