#include"bits/stdc++.h"
#include<unordered_set>
#include<unordered_map>
#include<random>
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

int N, K;
ll x[50], y[50];
vector<ll> zX, zY;

int sum[100][100] ={};

signed main(){
	cin >> N >> K;
	rep(i, N){
		cin >> x[i] >> y[i];
		zX.pb(x[i]);
		zY.pb(y[i]);
	}
	zX.pb(LLONG_MIN);
	sort(all(zX));
	zX.erase(unique(all(zX)), zX.end());
	zY.pb(LLONG_MIN);
	sort(all(zY));
	zY.erase(unique(all(zY)), zY.end());

	rep(i, N){
		sum[lower_bound(all(zX), x[i])-zX.begin()][lower_bound(all(zY), y[i])-zY.begin()]++;
	}
	rep(i, zX.size()){
		if(i == 0) continue;
		rep(j, zY.size()){
			sum[i][j] += sum[i-1][j];
		}
	}
	rep(i, zX.size()){
		rep(j, zY.size()){
			if(j == 0) continue;
			sum[i][j] += sum[i][j-1];
		}
	}

	ll ans = LLONG_MAX;
	rep(i, zX.size()){
		if(i == 0) continue;
		rep(j, zY.size()){
			if(j == 0) continue;
			for(int k=i; k<zX.size(); k++){
				for(int l=j; l<zY.size(); l++){
					if(sum[k][l]-sum[i-1][l]-sum[k][j-1]+sum[i-1][j-1] >= K){
						ans = min(ans, (zX[k]-zX[i])*(zY[l]-zY[j]));
					}
				}
			}
		}
	}
	cout << ans << endl;
}