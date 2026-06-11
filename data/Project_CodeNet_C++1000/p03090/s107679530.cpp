#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;

int main(){
	int n;cin>>n;
	set<P>se;
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
		se.insert(P(i+1,j+1));
	}
	if(n%2==0){
		for(int i=1;i<=n/2;i++){
			se.erase(P(i,n-i+1));
		}
	}
	else{
		for(int i=1;i<=n/2;i++){
			se.erase(P(i,n-i));
		}
	}
	cout<<se.size()<<endl;
	for(auto p:se){
		cout<<p.first<<' '<<p.second<<endl;
	}
}