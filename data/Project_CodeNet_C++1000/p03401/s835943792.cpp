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
	int n;
	cin >>n;
	VI a(n+2);
	a[0] = a[n+1]= 0;
	rep(i, n) cin >>a[i+1];
	n+=2;
	int sm = 0;
	rep2(i, 1, n+1) sm += abs(a[i] - a[i-1]);
	rep2(i, 1, n-1){
		int w = sm;
		w -= abs(a[i]-a[i-1]) + abs(a[i+1]-a[i]);
		w += abs(a[i-1] - a[i+1]);
		cout <<w <<"\n";
	}
	return 0;


}
