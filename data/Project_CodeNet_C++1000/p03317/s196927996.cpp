#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n,k;
	cin>>n>>k;
	long long int s=n;
	while(n--){
		long long int x;
		cin>>x;
	}
	long long int u=(s-1);
	long long int d=(k-1);
	if(u%d==0){
		cout<<u/d;
	}
	else{
		cout<<(u/d)+1;
	}
	return 0;
}