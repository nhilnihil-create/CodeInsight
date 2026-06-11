#include<bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<P1,ll> P2;
const ll INF=100000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};


int main() {

	string s;
	cin>>s;

	int a=0,b=0,c=0,ma=0;
	rep(i,s.size()){
		if(s[i]=='a')a++;
		if(s[i]=='b')b++;
		if(s[i]=='c')c++;
	}
	ma=max(a,b);
	ma=max(ma,c);
	if(ma-a>1)cout<<"NO"<<endl;
	else if(ma-b>1)cout<<"NO"<<endl;
	else if(ma-c>1)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;

	return 0;
}
