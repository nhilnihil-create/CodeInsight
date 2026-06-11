#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int N; cin>>N;
	int a; map<int,int> cnt;
	rep(i,0,N){ cin>>a; cnt[a]++; }
	int ans = 0;
	for(pair<int,int> p:cnt){
		if(p.first > p.second) ans += p.second;
		else ans += p.second - p.first;
	}cout<<ans<<endl;
}