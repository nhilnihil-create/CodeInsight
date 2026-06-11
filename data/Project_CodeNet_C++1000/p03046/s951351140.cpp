#include <bits/stdc++.h>

using namespace std;


int main() {
	int m,k;
	cin>>m>>k;
	if(k>(1<<m)-1){
		cout<<-1;
		return 0;
	}
	if(m==0){
		cout<<"0 0";
		return 0;
	}
	if(m==1) {
		if(k==1) cout<<-1;
		else cout<<"0 0 1 1";
		return 0;
	}
	if(k==0){
		for(int i=0;i<=(1<<m)-1;i++){
			cout<<i<<" ";
		}	
		for(int i=(1<<m)-1;i>=0;i--){
			cout<<i<<" ";
		}	
		return 0;
	}
	vector<int>p;
	p.push_back(0);
	p.push_back(k);
	p.push_back(0);
	for(int i=1;i<=(1<<m)-1;i++){
		if(i==k)continue;
		p.push_back(i);
	}
	p.push_back(k);
	for(int i=(1<<m)-1;i>=1;i--){
		if(i==k)continue;
		p.push_back(i);
	}
	for(int i=0;i<(int)p.size();i++){
		cout<<p[i]<<" ";
	}
	return 0;
}