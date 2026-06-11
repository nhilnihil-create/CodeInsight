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
	ll n,a,b;
	bool can=true;
	cin >>n>>a>>b;
	if(a*b <n){
		//clog<<"A";
		can=false;
	}
	if(a+b -1>n){
		//clog<<"B";
		can=false;
	}
	if(!can){
		cout<<-1<<endl;
		return 0;
	}
	ll at=n;
	ll count=0;
	ll lim=b+1;
	ll last=0;
	ll det=0;
	V ans(n);
	for(int i=0;i<b;i++){
		lim--;
		if(i==0){
			//clog<<"["<< n-a+1<<" ... "<<n<<"]"<<endl;
			for(ll j=n-a+1;j<=n;j++){
				ans[count]=j;
				//clog<<ans[count]<<" ";
				count++;
			}
			//clog<<endl;
			last=n-a+1;
		}else{
			//clog<<"lim:"<<lim<<endl;
			det=max(lim,last-a);
			for(ll j=det;j<last;j++){
				ans[count]=j;
				//clog<<ans[count]<<" ";
				count++;
			}
			last=det;
			//clog<<endl;
		}
	}
	//clog<<endl;
	rep(i,n){
		cout<<ans[i];
		if(i!=n-1){
			cout<<" ";
		}
	}
	cout<<endl;
}
/*
5 3 2 => [3,4,5] [1,2]
3 4 1 5 2

6 3 3  => [4 5 6 ][3] [1 2]
4 5 3 6 1 2
[4 5 6] [2 3] [1] 
4 5 2 3 6 1
6 3 4 -> [4 5 6] [3] [2] [1]
4  3 5  2 6 1
n a b => nから最大a要素のグループをb作る
6 2 4
[5 6] [3 4] [2] [1]
5 3 6 4 2 1
6 2 5
[5 6] [4] [3] [2] [1]
5 4 6 3 2 1
6 2 3
[5 6] [3 4] [2 1]
7 2 3
[6 7] [4 5] [2 3] [1]

*/