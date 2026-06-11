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
//const int PI = acos(-1);
int main(){
	int n;cin>>n;
	int a =0,b=0,ab=0,same=0;
	rep(i,n){
		string s;
		cin>>s;
		rep(j,s.length()-1){
			if(s[j]=='A'&&s[j+1]=='B')ab++;
		}
		if(s[0]=='B')b++;
		if(s[s.length()-1]=='A')a++;
		if(s[s.length()-1]=='A'&&s[0]=='B')same++;
	}
	int ans = ab+min(a,b);
	if(same==a&&same==b&&same!=0)ans--;
	cout<<ans<<endl;
}