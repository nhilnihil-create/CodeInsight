#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,l[15];
int s;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	sort(l,l+n);
	for(int i=0;i<n-1;i++){
		s=s+l[i];
	}
	if(l[n-1]<s){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	
}
