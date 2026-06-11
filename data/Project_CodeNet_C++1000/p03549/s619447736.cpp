#include <bits/stdc++.h>
using namespace std;

double kai(int n){
    double p=1;
	for(int i=0;i<n;i++) p/=2;
    double pp=(1-p)/p;
    return 1+p*pp+p*pp*pp;
}

int main(){
	int n,m,ans;
  	cin>>n>>m;
    int time=100*n+1800*m;
  	ans=time*kai(m);
    cout<<ans<<endl;
}  