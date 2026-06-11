#include<bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define ll long long
#define MOD (ll)1e9+7
#define REP(i,b,e) for(int (i)=b;(i)<e;(i)++)
const ll INF= 1LL << 60;

class UnionFind {
	vector<int> data;
public:
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};


//入力
ll N;
vector<ll> A;
vector<ll> B;
int main(){
  cin >> N;
  REP(i,0,N){
    ll a,b;
    cin >> a>>b;
    A.push_back(a);
    B.push_back(b);
  }
  ll ans=0;
  bool flag=true;
  ll min=(ll)1e9+10;
  REP(i,0,N){
    if(A[i]!=B[i]){
      flag=false;
    }
    ans+=A[i];
    if(A[i]>B[i]){
      chmin(min,B[i]);
    }
  }
  ans-=min;
  
  if(flag){
    cout<<0<<endl;
  }else{
    cout<<ans<<endl;
  }
  return 0;
}