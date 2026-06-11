#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	int h,w,d;cin>>h>>w>>d;
	vector<ll> x(100005,0);
	vector<ll> y(100005,0);
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			ll p;cin>>p;
			x[p] = i + 1;y[p] = j + 1;
		}
	}

	int q;cin>>q;
	int i = 0;
	vector<ll> a(100005,0);
	while(i <= a.size()){
		if(i <= d){
			a[i] = 0;
		}
		else{
			a[i] = a[i - d] + abs(x[i] - x[i - d]) + abs(y[i] - y[i - d]);
		}
		i++;
	}
	for(int i = 0; i < q; i++) {
		int l,r;cin>>l>>r;
		cout << a[r] - a[l] << endl;
	}
	return 0;
}