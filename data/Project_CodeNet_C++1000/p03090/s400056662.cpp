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
	int n;
	cin >>n;
	set<pair<int,int>>ans;
	if(n%2==0){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(1+n==i+j){continue;}
				ans.insert(mp(i,j));
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(n==i+j){continue;}
				ans.insert(mp(i,j));
			}
		}
	}
	cout<<ans.size()<<endl;
	repi(itr,ans){
		cout<<(itr->F)<<" "<<(itr->S)<<endl;
	}


	
}
/*
1 2 3 4 

1 4
2 3

1 2 4 3

1~6
1:2 3 4 5 (6)= 20-6
2:1 3 4 (5) 6= 19-5
3:1 2 (4) 5 6= 18-4
4:1 2 (3) 5 6 =17-3
5:1 (2) 3 4 6=16-2
6:(1) 2 3 4 5=15-1

1 2 3 4 5

  3
1 5 2
  4

1 2 3 (4) 5 = 14
2 1 (3) 4 5 = 13
3 1 (2) 4 5=12
4 (1) 2 3 5 = 11
5  1 2 3 4=10
15*2=30 6

1 2 3

1 3
2 3

1~7
1 2 3 4 5 7 = 21
2 1 3 4 6 7 = 21
3 1 2 5 6 7 = 21
4 1 2 5 6 7 = 21
5 1 3 4 6 7 = 21 
6 2 3 4 5 7 = 21
7 1 2 3 4 5 6 = 21
*/