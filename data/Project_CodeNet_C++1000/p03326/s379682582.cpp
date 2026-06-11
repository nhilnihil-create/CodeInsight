#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	long long ret = 0;
	vector<long long>arr[3];
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			long long a;
			cin>>a;
			arr[j].push_back(a);
		}
	}
	for(int state = 0; state<8; state++){
		vector<long long>temp;
		for(int i=0; i<n; i++){
			long long curr = 0;
			for(int j=0; j<3; j++){
				if((1<<j)&state) curr+=arr[j][i]*-1;
				else curr+=arr[j][i];
			}
			temp.push_back(curr);
		}
		sort(temp.begin(),temp.end());
		reverse(temp.begin(),temp.end());
		long long sum = 0;
		for(int i=0; i<m; i++) sum+=temp[i];
		ret = max(ret,sum);
	}
	cout<<ret;
}