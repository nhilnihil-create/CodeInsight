#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	int ans=0;
	rep(i,n){
		int a; cin>>a;
		ans+=a;
	}
	cout<<ans-n<<endl;
}