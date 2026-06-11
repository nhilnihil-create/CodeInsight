#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[114514],b[114514];
int main() {
	ll n;
	string a,b,c;
	ll cnt=0;
	cin>>n>>a>>b>>c;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			if(b[i]!=c[i]){
				if(c[i]!=a[i])cnt+=2;
				else cnt++;
			}else cnt++;
		}else if(b[i]!=c[i])cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}