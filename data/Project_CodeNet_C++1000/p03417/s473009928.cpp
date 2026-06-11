#include <bits/stdc++.h>


#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int MD = (int)1e9 + 7; typedef vector<ll> VL;
void dbg(){ cerr << "\n"; }  template <class T, class ...T2>
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	ll n, m;
	cin >>n >>m;
	/*
	vector<VI> ba(n, VI(m, 0));
	rep(i, n) rep(j, m){
		
		rep2(p,-1,2) rep2(q,-1,2){
			if(i+p<0 || i+p>=n || j+q<0 || j+q>=m) continue;
			ba[i+p][j+q] ^=1;
		}
	}
	
	for(auto xl: ba){for(auto x :xl) cerr<<x<<" ";dbg();}
	*/
	if(n==2 ||m==2) cout << 0 <<"\n";
	else if(n==1 && m==1) cout <<1 <<"\n";
	else if(n==1 || m==1) cout << max(n, m)-2 <<"\n";
	else cout << (m-2) * (n-2) <<"\n";
	return 0;
}
