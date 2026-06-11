#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll MOD=1777777777;
const ll INF=1000000000;
const ll LINF=4000000000000000010;
vector<int> v[100010];
int id[100010];
bool vis[100010];
int main(){
	int n;cin>>n;
	int s=0;
	bool f=true;
	for(int i=1;i<=1000;i++){
		s+=i;
		if(s==n){
			f=false;
			s=i;
			break;
		}
		if(s>100000){
			break;
		}
	}
	if(f){
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
	int c=(n*2)/s;
	cout<<(n*2)/s<<endl;
	int k=1;
	cout<<s<<" ";
	for(int i=0;i<s;i++){
		cout<<k;
		v[0].push_back(k);
		k++;
		if(i<s-1)cout<<" ";
	}
	cout<<endl;
	for(int i=0;i<c-1;i++){
		cout<<s<<" ";
		int co=0;
		id[i+1]=i+1;
		for(int j=max(i-s+1,0);j<=i;j++){
			cout<<v[j][id[j]]<<" ";
			v[i+1].push_back(v[j][id[j]]);
			id[j]++;
			co++;
		}
		while(co<s){
			cout<<k<<" ";
			k++;
			co++;
			v[i+1].push_back(k-1);
		}
		cout<<endl;
	}
}	
