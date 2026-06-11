#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second
#define MAXN 201010

int A[MAXN];
int B[MAXN];
int N,ans;
vi V;
vi O;

int main(){
	cin>>N;
	for (int i=1;i<=N;++i){
		cin>>A[i];
	}
	for (int i=1;i<=N;++i){
		cin>>B[i];
	}
	for (int bit=0;bit<=29;++bit){
		V.clear();
		O.clear();
		int tmp=0;
		for (int i=1;i<=N;++i){
			V.pb(A[i]%(1<<bit));
			tmp += ((A[i]&(1<<bit)) > 0)*N;
			tmp %= 2;
		}
		sort(ALL(V));
		for (int i=1;i<=N;++i){
			O.pb(B[i]%(1<<bit));
			tmp += ((B[i]&(1<<bit)) > 0)*N;
			tmp%=2;
		}
		// cout<<tmp<<'\n';
		sort(ALL(O));
		reverse(ALL(V));
		// for (auto i : O)cout<<i<<' ';cout<<'\n';
		// for (auto i : V)cout<<i<<' ';cout<<'\n';
		int ind = -1;
		for (auto i : O){
			while (ind+1<N && V[ind+1]+i >= (1<<bit))++ind;
			tmp += (ind + 1);
			tmp %= 2;
		}
		ans += (tmp%2)*(1<<bit);
		// return 0;
	}
	cout<<ans;
}