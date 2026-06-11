#include<bits/stdc++.h>
using namespace std;

int n,bil,mini,k,arr[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	mini = 1e9;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
	}
	sort(arr + 1,arr + n + 1);
	for(int i = 1;i <= n - k + 1;i++){
		bil = arr[i + k - 1] - arr[i];
		if(bil < mini){
			mini = bil;
		}
	}
	cout<<mini<<endl;
}
