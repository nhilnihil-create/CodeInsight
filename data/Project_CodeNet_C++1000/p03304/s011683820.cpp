#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int n,m,d;cin>>n>>m>>d;
	double ans;
	if(d == 0) ans = 1. / n;
	else ans = 2.0 * (n - d) / n / n;
    cout.precision(10);
	cout<<fixed<<ans * (m - 1)<<endl;
}