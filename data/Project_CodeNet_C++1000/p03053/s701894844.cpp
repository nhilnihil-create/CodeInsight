#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1000000007;

#define vec              vector<int>
#define vecll            vector<ll>
#define vecd             vector<double>
#define vecst            vector<string>
#define vecb             vector<bool>
#define v2(v,n,m,init)   vector<vector<int>>  v(n, vector<int>(m, init))
#define vb2(v,n,m,init)  vector<vector<bool>> v(n, vector<bool>(m, init))
#define vll2(v,n,m,init) vector<vector<ll>>   v(n, vector<ll>(m, init))

#define rep(i,n)         for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n)       for(ll i=(ll)m; i<(ll)n; i++)
#define arr(var, n)      vec var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vecll var(n); rep(i,n){cin >> var[i];}
#define arrst(var, n)    vecst var(n); rep(i,n){cin >> var[i];}
#define all(var)         (var).begin(), (var).end()
#define sortall(var)     sort(all(var))
#define uniqueall(v)     v.erase(unique(v.begin(), v.end()), v.end());
#define pb(var)          push_back(var)
#define prt(var)         cout << (var) << "\n"
#define prtd(n, var)     cout << fixed << setprecision(n) << (var) << "\n"
#define prtfill(n, var)  cout << setw(n) << setfill('0') << (var);
#define prt2(v1, v2)     cout << (v1) << " " << (v2) << "\n"
#define prt3(v1, v2, v3) cout << (v1) << " " << (v2) << " " << (v3) << "\n"
#define prtall(v)        rep(i,v.size()){cout<<v[i]<<(i!=v.size()-1?" ":"\n");}
template <typename T>
bool chmax(T &a, const T& b){if(a<b){a=b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T& b){if(a>b){a=b; return true;} return false;}
//------------------------------------------------------------------

int main(void){
	int h, w;
	cin >> h >> w;
	arrst(a,h);

	vb2(v, h, w, false);
	vector<pair<int, int>> q;
	int ct=0;
	rep(i,h){
		rep(j,w){
			if(a[i][j]=='.') ct++;
			else q.push_back(make_pair(i,j)), v[i][j]=true;
		}
	}

	int ans=0;
	while(ct){
		ans++;
		vector<pair<int, int>> nextq;
		for(auto k : q){
			int i = k.first;
			int j = k.second;
			if(i!=0){
				if(!v[i-1][j]) ct--, v[i-1][j]=1, nextq.push_back(make_pair(i-1, j));
			}
			if(i!=h-1){
				if(!v[i+1][j]) ct--, v[i+1][j]=1, nextq.push_back(make_pair(i+1, j));
			}
			if(j!=0){
				if(!v[i][j-1]) ct--, v[i][j-1]=1, nextq.push_back(make_pair(i, j-1));
			}
			if(j!=w-1){
				if(!v[i][j+1]) ct--, v[i][j+1]=1, nextq.push_back(make_pair(i, j+1));
			}
		}

		q=nextq;
	}

	prt(ans);
}
