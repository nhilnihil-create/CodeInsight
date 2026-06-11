#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int MD = (int)1e9 + 7;
void dbg(){ cerr << "\n"; }  template <typename T,typename ...T2>
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }

int n, q;
string s, t, d;

int fdo(int pos){
	rep(i, q){
		if(s[pos] != t[i]) continue;
		pos += d[i]=='L'? -1: 1;
		if(pos < 0 ) return 2;
		if(pos >=n ) return 3;
	}
	return 1;
}

int fnc(bool lr){
	int hi=n, lw=-1;
	while(hi - lw >1){
		int md = (hi + lw) >>1;
		if(lr) (fdo(md) == 2? lw: hi) = md;
		else   (fdo(md) == 3? hi: lw) = md;
	}
	return hi;
}


int main(){
	cin.tie(0); ios_base::sync_with_stdio(false);
	cin >>n>>q>>s;

	rep(i,q){
		string x,y; cin >>x >>y;
		t+=x; d+=y;
	}
	cout << fnc(false) - fnc(true) <<"\n";
	
}

