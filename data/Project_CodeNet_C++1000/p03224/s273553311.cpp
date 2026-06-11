#include <bits/stdc++.h>
using namespace std;

#define rep(i,N) repv(i,0,N)
#define reps(i,N) repvs(i,0,N)
#define repv(i,a,b) for(int i=a;i<b;i++)
#define repvs(i,a,b) for(int i=a+1;i<=b;i++)
#define repr(i,N) for(int i=N-1;i>=0;i--)
#define reprs(i,N) for(int i=N;i>0;i--)

#define d(a) if(isDebugMode) cout<<#a<<"="<<a<<","
#define d2(a,b) if(isDebugMode) cout<<#a<<"="<<a<<","<<#b<<"="<<b
#define d3(a,b,c) if(isDebugMode) cout<<#a<<"="<<a<<","<<#b<<"="<<b<<","<<#c<<"="<<c
#define d4(a,b,c,d) if(isDebugMode) cout<<#a<<"="<<a<<","<<#b<<"="<<b<<","<<#c<<"="<<c<<","<<#d<<"="<<d
#define da(arr,N){if(isDebugMode){rep(i,N+1){if(arr[i]==INF)printf("INF ");else cout<<arr[i]<<" ";} cout<<endl;}}
#define da2(arr,N,M){if(isDebugMode)rep(i,N+1){rep(j,M+1){if(arr[i][j]==INF)printf(" INF");else printf(" %3d",arr[i][j]);}cout<<endl;}}
#define pb push_back
#define pob pop_back
#define s(a) cout<<a<<endl;

auto chmax =[](int &a,int b){ a = max(a, b);};
auto chmin =[](int &a,int b){ a = min(a, b);};

typedef long long ll;
typedef pair<int,int> P;
const int INF = 100000000;
const int MOD = 1000000007;
const int dx[4] = { 0, 1, 0,-1};
const int dy[4] = { 1, 0,-1, 0};

bool isDebugMode=1;
//--------------------------------------//
int n;
int b[100001];
vector<int> t;
void solve(){
	int c=1;
	for(int i=2;c<=100000;i++){
		b[c]=i-1;
		c+=i;
	}
	if(b[n]==0){cout<<"No"<<endl;return;}
	vector<int> v;
	c=0;
	int A=b[n];
	int a=A;
	int p=1;
	cout<<"Yes"<<endl;
	cout<<A+1<<endl;
	while(a>=0){
		t.clear();
		t.pb(A);
		rep(i,a){
			t.pb(p+i);
		}
		rep(i,v.size()){
			t.pb(v[i]+c-1);
		}
		v.pb(p-c);
		p+=a;
		a--;
		c++;
		rep(i,t.size()){
			if(i!=t.size()-1) 
				printf("%d ",t[i]);
			else
				printf("%d\n",t[i]);
		}
	}
}

int main(){
	cin>>n;
	solve();
	return 0;
}
