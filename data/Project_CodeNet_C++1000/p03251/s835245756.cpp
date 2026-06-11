#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define ote(x) cout<<(x)<<endl
#define all(x) (x).begin(),(x).end()
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define rpz(i,e) rp(i,0,(e))
#define irp(i,s,e) for(int i=(s);i>(e);--i)
#define irpz(i,s) irp(i,(s),-1)
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}
template<class T>void outarr(int s,int e,vector<T> &V){
	for(int i=s;i<e;i++)cout<<V[i]<<(i<e-1?" ":"\n");
}
// outarr<int>(0,V.size(),V);
// outarr<ll>(0,V.size(),V);

int N,M,X,Y;
vi XX,YY;

bool solve(){
	vector<pair<int,int>> V;//<point,state:[0|1]=[A|B]>
	V.emplace_back(X, 0);
	rp(i,0,N){
		V.emplace_back(XX[i], 0);
	}
	V.emplace_back(Y, 1);
	rp(i,0,M){
		V.emplace_back(YY[i], 1);
	}

	sort(all(V));

	// for(auto x:V){printf("%3d %3d\n",x.first,x.second);}puts("");//

	// bool ret = false;

	int pre_point, pre_state;
	int point, state;
	tie(pre_point, pre_state) = V[0];
	rp(i, 1, V.size()){
		tie(point, state) = V[i];
		if(pre_state > state){
			return false;
		}
		else if(pre_state < state){
			if(pre_point == point){
				return false;
			}
		}
		pre_point = point;
		pre_state = state;
	}

	return true;
	// return ret;
}

int main(){
	cin>>N>>M>>X>>Y;
	XX.resize(N); rp(i, 0, N) cin>>XX[i];
	YY.resize(M); rp(i, 0, M) cin>>YY[i];
	cout<< (solve()? "No War":"War") <<endl;
}
