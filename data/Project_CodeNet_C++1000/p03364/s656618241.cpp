#include<bits/stdc++.h>
using namespace std;
string a[300],b[300];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	cin>>a[i],b[i].resize(n);
	int ans=0;
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				b[i][j]=a[i][(j+k)%n];
		bool ok=true;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(b[i][j]!=b[j][i])
					ok=false;
		ans+=ok;
	}
	cout<<ans*n<<endl;
}
