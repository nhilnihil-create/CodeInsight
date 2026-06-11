#include<bits/stdc++.h>
#include<iomanip>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<string,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<Pi,int> P2;
const ll INF=1000000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};


int main() {

	int n;
	cin>>n;
	cout<<(n-3+1)*180<<endl;
	return 0;

}
