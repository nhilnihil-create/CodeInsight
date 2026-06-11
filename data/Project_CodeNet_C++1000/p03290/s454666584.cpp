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
int main(){
	int d,g;
	int ans=INF;
	cin >>d>>g;
	VP data(d);
	rep(i,d){
		cin>>data[i].F>>data[i].S;
	}
	int cnt=0;
	int at=0;
	int ter=0;
	rep(bit,1<<d){
		cnt=0;
		at=0;
		rep(i,d){if(bit & (1<<i)){
				at+=data[i].F*100*(i+1)+data[i].S;
				cnt+=data[i].F;
				}
		}
		if(at <g){
			ter=d-1;
			while(bit & (1<<ter)){
				ter--;
			}
			//cnt+=(g-at/*+ter*100 -1*/)/((ter+1)*100);
			if ((g - at + (ter + 1) * 100 - 1) / ((ter + 1) * 100) <=data[ter].F){
				cnt += (g - at + (ter + 1) * 100 - 1) / ((ter + 1) * 100);
				}else{
					continue;
				}
		}
		chmin(ans,cnt);
		//clog<<cnt<<" "<<bitset<10>(bit)<<endl;

			
	}
	cout<<ans<<endl;
}