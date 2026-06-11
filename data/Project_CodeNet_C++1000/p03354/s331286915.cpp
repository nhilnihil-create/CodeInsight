#include<bits/stdc++.h>
using namespace std;
int p[100005];
set<int>s[100005];

int u_find(int a){
	if(p[a]==0) return a;
	return p[a] = u_find(p[a]);
}
void merge(int a,int b){
	a = u_find(a);
	b = u_find(b);
	if(a==b) return;
	p[a] = b;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	int arr[n+1]={0};
	for(int i=1; i<=n; i++) cin>>arr[i];
	while(m--){
		int a,b;
		cin>>a>>b;
		merge(a,b);
		
	}
	for(int i=1; i<=n; i++){
		s[u_find(i)].insert(arr[i]);
	}
	int ret = 0;
	for(int i=1; i<=n; i++){
		if(s[u_find(i)].find(i)!=s[u_find(i)].end()) ret++;
	}
	cout<<ret;
}