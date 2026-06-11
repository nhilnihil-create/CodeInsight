#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int main(){
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	
	int ret=1000000000;
	for(int z=0;z<=max(x,y);z++){
		chmin(ret,z*(2*c)+max(x-z,0)*a+max(y-z,0)*b);
	}
	cout<<ret<<endl;
}

