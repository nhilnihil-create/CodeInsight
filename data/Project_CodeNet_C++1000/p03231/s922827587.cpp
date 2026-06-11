#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define until(x) while(!(x))
#define unless(x) if(!(x))
#define all(x) (x).begin(),(x).end()

map<int,char> ma;
int32_t main(){
	int n,m;
	string s,t;
	cin>>n>>m;
	cin>>s>>t;
	int len = (n*m)/__gcd(n,m);
	for(int i=0;i<n;i++){
		ma[i*(len/n)+1]=s[i];
	}
	for(int i=0;i<m;i++){
		if(ma.count(i*(len/m)+1)){
			if(ma[i*(len/m)+1]!=t[i]){
				cout<<-1;
				return 0;
			}
		}
	}
	cout<<len;
}
