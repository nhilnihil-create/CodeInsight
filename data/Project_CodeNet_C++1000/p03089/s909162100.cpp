#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define until(x) while(!(x))
#define unless(x) if(!(x))
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define pc __builtin_popcount

int32_t main(){
	int n;
	cin>>n;
	vector<int> ar(n+1);
	vector<int> v;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	while(!ar.empty()){
		for(int i=ar.size()-1;i>=0;i--){
			if(ar[i]==i){
				v.push_back(i);
				ar.erase(ar.begin()+i);
				goto cont;
			}
		}
		cout<<"-1";
		return 0;
		cont:1;
	}
	for(int i=v.size()-2;i>=0;i--){
		cout<<v[i]<<"\n";
	}
}
