#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
const double PI = acos(-1);

int main(){
	int n;cin>>n;
	vi b(n);
	rep(i,n)cin>>b[i];
	vi ans(n);
	int able = -1;
	rep(i,n){
		able =-1;
		rep(j,b.size()){
			if(b[j]==j+1){
				able=j;
			}
		}
		if(able==-1){
			cout<<-1<<endl;
			return 0;
		}
		else{
			ans[i]=able+1;
			b.erase(b.begin()+able);
		}
	}
	reverse(been(ans));
	rep(i,n){
		cout<<ans[i]<<endl;
	}
}