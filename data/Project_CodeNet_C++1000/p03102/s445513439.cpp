#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n,m,c;
	cin>>n>>m>>c;
	int arr[m], ans =0;
	for(int i=0; i<m; i++)cin>>arr[i];
	for (int i = 0; i < n; i++){
		int check = 0;
		for(int j=0; j<m; j++){
			int x; cin>>x;
			check+=(arr[j]*x);
		}
		if(check+c>0)ans++;
	}
	cout<<ans<<endl;
}
