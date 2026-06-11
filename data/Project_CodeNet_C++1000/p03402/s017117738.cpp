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
	int a, b;
	cin >>a >>b;
	
	vector<string> vs(100, string(100, '.'));
	rep(i, 50) vs[i] = string(100, '#');
	
	int za = a-1, zb = b-1;
	rep(i, 48) rep(j, 100) if(i%2==0 && j%2==0 && za-- >0) vs[i][j]='.';
	repr(i, 99, 52) rep(j, 100) if(i%2 && j%2==0 && zb-- >0) vs[i][j]='#';
	cout <<"100 100\n";
	for(auto x :vs) cout<<x<<"\n";
	return 0;


}
