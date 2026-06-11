#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main(){
	ll n,a,b,c,d,e;cin>>n>>a>>b>>c>>d>>e;
	ll f=min({a,b,c,d,e});
	cout<<(n+f-1)/f+4<<endl;
}