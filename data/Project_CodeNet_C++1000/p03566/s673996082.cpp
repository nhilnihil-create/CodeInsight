#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define mfill(x,y) memset(x,y,sizeof(x))
#define all(v) v.begin(), v.end()
#define in(x,y,h,w) if(0<=x&&x<h&&0<=y&&y<w)
#define y0 y12345
#define y1 y54321

#ifdef LOCAL
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ul = unsigned long;
using ll = long long;
using P = pair<int, int>;
using vint = vector<int>;using vvint = vector<vector<int>>;
using vll = vector<ll>;using vvll = vector<vector<ll>>;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b;return 1;}return 0;}
template <class T>void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
	v.assign(a, vector<T>(b, t));
}
template <class T>T gcd(T &a, T &b){if(a<b){swap(a,b);} T r = a%b; while(r!=0){a=b;b=r;r=a%b;} return b;}

vint dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
vint dx8 = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8 = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	debug("debug test\n");
   	int n,m;cin>>n;
	vint t(n), v(n);
	vint a(n), b(n);
	rep(i, n){
		cin>>t[i];
	}
	rep(i, n){
		cin>>v[i];
	}
	rep(i, n){
		if(i == 0){
			a[i] = 0;
		}else{
			a[i] = min(v[i-1], a[i-1]+t[i-1]);
		}
	}
	for(int i = n-1;i >= 0;i--){
		if(i == n-1){
			b[i] = 0;
		}else{
			b[i] = min(v[i+1], b[i+1]+t[i+1]);
		}
	}
	double ans = 0.0;
	rep(i, n){
		if(a[i] >= v[i]){
			if(b[i] >= v[i]){
				ans += (double)v[i]*(double)t[i];
			}else if((double)b[i]+(double)t[i] >= (double)v[i]){
				ans += (double)v[i]*(double)t[i] - (double)((double)v[i]-(double)b[i])*((double)v[i]-(double)b[i])/2.0;
			}else{
				ans += (double)b[i]*(double)t[i] + (double)t[i]*(double)t[i]/2.0;
			}
		}else{
			if(b[i] >= v[i]){
				if(a[i]+t[i] >= v[i]){
					ans += (double)v[i]*(double)t[i] - (double)((double)v[i]-(double)a[i])*((double)v[i]-(double)a[i])/2.0;
				}else{
					ans += (double)a[i]*(double)t[i] + (double)t[i]*(double)t[i]/2.0;
				}
			}else{
				if((double)((double)a[i]+(double)b[i]+(double)t[i])/2.0 > (double)v[i]){
					ans += (double)v[i]*(double)t[i] - (double)((double)v[i]-(double)a[i])*((double)v[i]-(double)a[i])/2.0 - (double)((double)v[i]-(double)b[i])*((double)v[i]-(double)b[i])/2.0;
				}else{
					double koux = (double)(b[i]+t[i]-a[i])/2.0;
					if(koux < 0.0){
						ans += (double)t[i]*(double)b[i] + (double)t[i]*(double)t[i]/2.0;
					}else if( koux > t[i]){
						ans += (double)t[i]*a[i] + (double)t[i]*(double)t[i]/2.0;
					}else{
						ans += (double)koux*(2*(double)a[i]+koux)/2.0 + (double)((double)t[i]-koux)*(2*(double)b[i]+(double)t[i]-koux)/2.0;
					}
				}
			}
		}
	}
	//cout << ans << endl;
	printf("%.15f\n", ans);
	return 0;
}
