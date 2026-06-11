#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) do{}while(0)
#endif




ll n;

int main(){
	cin >> n;
	vector<int> b(n);
	vector<int> d(n);
	vector<int> result;
	
	rep(i,n){
		cin >> b[i];
		b[i]--;
		d[i] = i - b[i]; // 挿入位置からの移動量
	}
	
	while ( d.size() ){
		//rep(i,SZ(b))
		//	cout << d[i] << " ";
		//cout << endl;
		//cout << endl;
		
		int pos = -1;
		rep(i,SZ(d)){
			if ( d[i] == 0 )
				pos = i;
		}
		if ( pos == -1 ){
			cout << -1 << endl;
			return 0;
		}
		result.push_back(pos);
		
		for ( int i = pos; i < SZ(d)-1; i++ ){
			d[i] = d[i+1]-1;
		}
		d.pop_back();
	}
	
	reverse(ALL(result));
	for ( auto it: result )
		cout << it+1 << endl;
	
	return 0;
}


