#include<bits/stdc++.h>
using namespace std;
#define sz(x) int(x.size())
#define pb push_back
#define ff first
#define ss second
typedef long long ll;

int main(){
	int n,k;cin>>n>>k;
	vector<int>vec(n);
	bool is0=false;
	for(int i=0;i<n;i++){
		cin>>vec[i];
		if(vec[i]==0)is0=true;
	}
	if(!is0){
		vec.pb(0);
		sort(vec.begin(),vec.end());
		k++;
	}
	int mn=INT_MAX;
	for(int i=0;i+k<=sz(vec);i++){
		//eval in range [i,i+k-1]
		if(vec[i]>0||vec[i+k-1]<0)continue;
		mn=min(mn,min(-2*vec[i]+vec[i+k-1],-vec[i]+2*vec[i+k-1]));
	}
	cout<<mn<<endl;
	
	return 0;
}
