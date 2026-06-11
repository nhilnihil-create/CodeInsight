#include<bits/stdc++.h>
using namespace std;
#define int 	long long int

int arr[1000][3];
void solve(int n,int m){

	int ans=INT_MIN;
	for(int i=0;i<8;i++){
		bitset<3> bits(i);
		vector<int> temp;
		for(int j=0;j<n;j++){
			int val=0;
			for(int k=0;k<3;k++){
				if(bits[k]){
					val+=arr[j][k];
				}
				else
					val-=arr[j][k];
			}
			temp.push_back(val);
		}
		int res=0;
		sort(temp.begin(),temp.end());
		reverse(temp.begin(),temp.end());
		for(int k=0;k<m;k++){
			res+=(temp[k]);
		}
		// temp.clear();
		ans=max(ans,res);
	}

	cout<<ans<<endl;
}

int32_t main(){
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>arr[i][j];
		}
	}

	solve(n,m);
}


