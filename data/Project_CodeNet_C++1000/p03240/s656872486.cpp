#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
int assume(int h, pair<int,int>c, pair<int,int>at){
	return max(0,h-abs(c.F-at.F)-abs(c.S-at.S));
}
int main(){
	int n;
	pair<pair<int,int>,int>ans;
	cin >>n;
	int down=INF;
	bool can=true;
	pair<int,int>at=mp(0,0);
	vector<pair<pair<int,int>,int>>data(n);
	int x,y,h;
	rep(i,n){
		cin>>x>>y>>h;
		data[i]=mp(mp(x,y),h);
		chmin(down,h);
	}
	for(h=down;h<=down+200;h++){
		for(at.F=0;at.F<=100;at.F++){
			for(at.S=0;at.S<=100;at.S++){
				can=true;
				rep(i,n){
					if(assume(h,at,data[i].F)!=data[i].S){
						can=false;
					}
				}
				if(can){
					printf("%d %d %d\n",at.F,at.S,h);
					return 0;
				}
			}
		}
	}
	//cout<<ans<<endl;
}