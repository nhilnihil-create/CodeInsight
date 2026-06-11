#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vi2 = vector<vector<int>>;
#define MP(a,b) make_pair((a),(b))
#define MT(...) make_tuple(__VA_ARGS__)

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)

#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl;
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl;

#define DCOUT(x,n) cout << fixed << setprecision(n) << (x) << endl;

#define sz(x) (int)(x).size()
#define HOGE cout << "hoge" << endl;
using P = pair<ll,ll>;

template<typename T>inline istream& operator>>(istream&i,vector<T>&v)
{REP(j,sz(v))i>>v[j];return i;}

const int INF = 1e9;

int main(){
	int R, G, B, N;
	cin >> R >> G >> B >> N;
	int count = 0;
	REP(r,N/R+1){
		REP(g,N/G+1){
			if((N-r*R-g*G)%B==0&&r*R+g*G<=N) count++;
		}
	}

	cout << count << endl;
}
