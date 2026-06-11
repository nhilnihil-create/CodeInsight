#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int siz=1e5;
const long inf=1e18;
int main(){
	int N; cin>>N;
	int t[2],a[2],b[2];
	t[0] = a[0] = b[0] = 0;
	rep(i,0,N){
		cin>>t[1]>>a[1]>>b[1];
		int x = t[1] - t[0];
		int y = abs(a[1]-a[0]);
		int z = abs(b[1]-b[0]);
		if(x < y + z || x % 2 != (y + z) % 2){
			cout<<"No"<<endl;
			return 0;
		}t[0] = t[1]; a[0] = a[1]; b[0] = b[1];
	}cout<<"Yes"<<endl;
}