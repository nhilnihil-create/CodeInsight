#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n,k; cin>>n>>k;
	if(n%2==0&&k<=n/2) cout<<"YES"<<endl;
	else if(n%2==1&&k<=(n+(2-1))/2) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}