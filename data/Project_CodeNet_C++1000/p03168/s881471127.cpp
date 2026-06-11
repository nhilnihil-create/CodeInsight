#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector<vector<int>> vvi;
#define deb(x) cout << #x << " : " << x << endl
#define deb2(x , y) cout << #x << " : " << x << " , "<< #y << " : " << y << endl
#define debv(x) for(auto i=x.begin();i!=x.end();i++) cout<<*i<<' ';cout<<endl
#define debp(x) for(auto i=x.begin();i!=x.end();i++) cout<<i->first<<':'<<i->second<<' ';cout<<endl
#define debvv(x) for(auto j=x.begin();j!=x.end();j++) { for(auto i=(*j).begin();i!=(*j).end();i++) cout<<*i<<' ';cout<<endl;}cout<<endl
#define rsz(x,n) x.clear(); x.resize(n)
#define rrsz(x,a,n) x.clear(); x.resize(n,a)
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define wt while(true)
#define all(x) x.begin(),x.end()
#define pb push_back
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define INF (1e9 + 7)
#define endl '\n'
int mod=1e9+7;

void solve() {
	int n;
	cin>>n;
	vector<double> prob(n);
	vector<vector<double>> chance(n+1,vector<double>(n+1,0));
	rep(i,n){
		cin>>prob[i];
	}
	chance[0][0]=1;
	reps(i,1,n+1){
		rep(j,n+1){
			if(j==0){
				chance[i][j]=(1-prob[i-1])*chance[i-1][j];
			}
			else{
				chance[i][j]=chance[i-1][j]*(1-prob[i-1]);
				chance[i][j]+=chance[i-1][j-1]*prob[i-1];
			}
		}
	}
  	//debvv(chance);
	double ans=0;
	reps(i,n/2+1,n+1){
		ans+=chance[n][i];
	}
	cout<<ans<<endl;
}

int main() {
	csl;
	int testcase=1;
  	cout.precision(10);
//	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		solve();
	}
	return 0;
}

