#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int N=100005;
const int P=998244353;

int n;
long long x,y,z;

void init(){
	cin>>x>>y;
	if(x>y) swap(x,y);
	z=x*y;
	long long w=sqrt(z);
	if(w*w==z){
		if(x==w){
			cout<<2*w-2<<endl;
		}
		else{
			cout<<2*w-3<<endl;
		}
	}
	else if(w*(w+1)>=z){
	//	if(x==w) cout<<2*w-3<<endl;
	//	else{
			cout<<2*w-2<<endl;
	//	}
	}
	else cout<<2*w-1<<endl;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) init();
	return 0;
}