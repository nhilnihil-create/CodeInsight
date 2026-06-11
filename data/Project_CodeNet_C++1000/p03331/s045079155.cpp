#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int keta(int x){
    int r=0,  k=0;
    while(x!=0){
        r=x%10; x/=10; k+=r;
    }
    return k;
}

int main(){
	int n; cin>>n;
	int ans=1e6+1;
	for(int i=1; i<n; i++){
		int a=i, b=n-i;
		int t=keta(a)+keta(b);
		ans=min(ans,t);
	}
	cout<<ans<<endl;
}