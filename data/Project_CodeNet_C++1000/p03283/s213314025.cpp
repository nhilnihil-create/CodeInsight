#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
typedef vector<ll> VL; const int MD = (int)1e9 + 7;
void dbg(){ cerr << "\n"; } template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, m, q;
	cin >>n >>m >>q;
	
	vector<VI> ss(n+2, VI(n+2)), sk(n+3, VI(n+3));
	rep(i, m){
		int l, r; cin >>l >>r;
		ss[l-1][r-1]++;
	}
	rep(i, n+2) rep(j, n+2){
		sk[i+1][j+1] = sk[i+1][j] + sk[i][j+1] - sk[i][j] + ss[i][j];
	}

	rep(i, q){
		int a, b; cin >>a >>b; 
		cout << sk[b][b] - sk[a-1][b] - sk[b][a-1] + sk[a-1][a-1] <<"\n";
	}
	return 0;
}
