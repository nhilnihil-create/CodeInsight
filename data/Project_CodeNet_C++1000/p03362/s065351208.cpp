#include<bits/stdc++.h>
using namespace std;
int maxn = 100000;
int eratoes[100005];
int main(){
	for(int i=2; i<=maxn; i++) eratoes[i] = i;
	for(int i=2; i*i<=maxn; i++){
		if(eratoes[i]==i){
			for(int j=i*i; j<=maxn; j+=i) eratoes[j] = i;
		}
	}
	vector<int>ret;
	for(int i=2; i<=55555; i++){
		if(eratoes[i]==i && i%5==1) ret.push_back(i);
	}
	int n;
	cin>>n;
	for(int i=0; i<n; i++) cout<<ret[i]<<" ";
}