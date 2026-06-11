#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v[1<<18];

int a[1<<18],tmp;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int m=(1<<n);
	for(int i=0;i<m;i++)
		cin>>a[i];
	
	for(int i=0;i<m;i++){
		v[i].push_back(make_pair(0,-1));
		v[i].push_back(make_pair(a[i],i));
		if(i!=0){
			for(int j=0;j<n;j++)
				if((1<<j)&i){
					v[i].push_back(v[i^(1<<j)][0]);
					v[i].push_back(v[i^(1<<j)][1]);
				}
			sort(v[i].begin(),v[i].end(),greater<pair<int,int> >());
			v[i].resize(unique(v[i].begin(),v[i].end())-v[i].begin());
			tmp=max(tmp,v[i][0].first+v[i][1].first);
			cout<<tmp<<'\n';
		}
	}
}
