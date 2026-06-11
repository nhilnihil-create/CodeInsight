#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
	int n,m; cin>>n>>m;
	int arr[m], ans=0;
	memset(arr, 0, sizeof(arr));
	for(int i=0; i<n; i++){
		int k; cin>>k;
		for (int i = 0; i < k; i++){
			int x; cin>>x;
			arr[x-1]++;
		}
	}
	for(int i=0; i<m; i++){
		if(arr[i]==n)ans++;
	}
	cout<<ans<<endl;
}
