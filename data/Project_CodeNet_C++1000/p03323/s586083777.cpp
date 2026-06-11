//Abhinav ---IIIT_A
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define f(i,x,n) for(int i=x;i<(int)n;++i)
#define vpii vector<pair<int,int>>
#define vi vector<int>
#define mpii map<pair<int,int>,int>
#define mpivpii map<int,vector<pair<int,int>>>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define mpi map<int,int>
#define vvi vector<vector<int>>
#define vvvi vector<vvi>
ld pie=3.141592653589;
int mod=1e9+7;

bool Compare(int a, int b)
{
   return a < b;
}
std::priority_queue<int, std::vector<int>, std::function<bool(int, int)>> pq(Compare);

vi pr;
void seive(){
	int p[100005]={0};
	f(i,2,100005){
		if(p[i]==0){
			pr.pb(i);
			for(int j=i*2;j<100005;j+=i) p[i]=1;
		}
	}
}


void solve(){
	int a,b; cin>>a>>b;
	if(a<=8 && b<=8) cout<<"Yay!\n";
	else cout<<":(\n";
}


int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t=1; //cin>>t;
  while(t--) solve();
  return 0;
}
// check for overflows dummy !!!