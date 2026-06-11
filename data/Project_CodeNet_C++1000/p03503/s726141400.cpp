#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<62;
const int INF = 1<<30;
const double PI=acos(-1);
int main(){
	int n;
	int ans=-INF;
	cin >>n;
	vector<int> hash(n,0);
	vector<vector<int>> pro(n,vector<int>(12,0));
	int bef;
	rep(i,n){
		rep(j,10){
			cin>>bef;
			hash[i]|=((bef)<<j);
		}
	}
	rep(i,n){
		rep(j,11){
			cin>>pro[i][j];
		}
		
	}
	int cnt =0;
	int tmp=0;
	for(int bit =1;bit<(1<<10);bit++){
		cnt=0;
		if(__builtin_popcount(bit)==0){
			continue;
		}
		for(int i=0;i<n;i++){
			tmp=bit & hash[i];

			cnt += pro[i][__builtin_popcount(tmp)];
			
		}
		if(chmax(ans,cnt))
		clog << bitset<10>(bit)<<" "<<cnt<<endl;
	}
	cout<<ans<<endl;
}