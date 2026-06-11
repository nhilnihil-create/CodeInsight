#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<vector<int> > v(n,vector<int>(3));
	for(int i=0;i<n-1;i++)
	cin>>v[i][0]>>v[i][1]>>v[i][2];
	int t;
	for(int i=0;i<n-1;i++){
		t=v[i][1];
		for(int j=i;j<n-2;j++){
			t+=v[j][0];
			t=max(t,v[j+1][1]);
			if(t%v[j+1][2]!=0)
			t+=v[j+1][2]-t%v[j+1][2];
		}
		t+=v[n-2][0];
		cout<<t<<endl;
	}
	cout<<0;
}