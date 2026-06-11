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
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}



ll cvf(ll s){
	if(s%4 == 0) return s;
	if(s%4 == 1) return 1;
	if(s%4 == 2) return s+1;
	return 0;
}


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	ll a, b;
	cin >>a >>b;
	
	//dbg("", cvf(a-1), cvf(b));
	if(a==0) cout << cvf(b) <<"\n";
	else cout <<( cvf(a-1) ^ cvf(b)) <<"\n";
	
	return 0;
}
