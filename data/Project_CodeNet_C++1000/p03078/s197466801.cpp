#include<bits/stdc++.h>
#define ford(i,a,b) for(int i=(a);i>=b;i--)
#define rep1(i,a,b) for(int i=(a);(i)<=(b);(i)++)
#define rep(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define ll long long
#define mpi map<int,int>
#define N 200005
#define pql priority_queue<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define str stringstream
using namespace std;
ll x,y,z,k;
vector<ll> ans,a(N),b(N),c(N);
int main() {
	cin>>x>>y>>z>>k;
	rep(i,0,x)cin>>a[i];
	rep(i,0,y)cin>>b[i];
	rep(i,0,z)cin>>c[i];
	sort(rall(a)); sort(rall(b)); sort(rall(c));
	rep(i,0,x)
		rep(j,0,y)
			rep(l,0,z){
				if(i*j*l>k)break;
				ans.push_back(a[i]+b[j]+c[l]);
			}
	sort(rall(ans));
	rep(i,0,k)cout<<ans[i]<<"\n";
	return 0;
}
