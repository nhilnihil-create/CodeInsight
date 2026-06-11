#include<bits/stdc++.h>
using namespace std;
int maxn = 100000;
int eratoes[100005];
int similar[100005];
int main(){
	for(int i=2; i<=maxn; i++) eratoes[i] = i;
	for(int i=2; i*i<=maxn; i++){
		if(eratoes[i]==i){
			for(int j=i*i; j<=maxn; j+=i) eratoes[j] = i;
		}
	}
	for(int i=2; i<=maxn; i++){
		if(eratoes[i]==i && eratoes[(i+1)/2]==(i+1)/2)
			similar[i] = true;
	}
	for(int i=1; i<=maxn; i++) similar[i]+=similar[i-1];
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<similar[b]-similar[a-1]<<'\n';
	}
}