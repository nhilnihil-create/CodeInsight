#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n,m;
	cin>>n>>m;
	long long int c=0,l=n;
	long long int arr[m+1];
	memset(arr,0,sizeof(arr));
	while(n--){
		long long int x;
		cin>>x;
		while(x--){
			long long int i;
			cin>>i;
			arr[i]++;
		}
	}
	for(long long int k=1;k<=m;k++){
		if(arr[k]==l){
			c++;
		}
	}
	cout<<c;
	return 0;
}