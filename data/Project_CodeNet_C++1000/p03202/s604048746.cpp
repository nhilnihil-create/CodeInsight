#include <bits/stdc++.h>
using namespace std;
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define in(x,y,h,w) x >= 0 && x < h && y >= 0 && y < w

#define int long long
//using ll = long long;
using P = pair<int,int>;

ostream &operator<<(ostream &os,const P &p){ return os << "(" << p.first << "," << p.second << ")"; }

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int n,a[200010];
vector<P> vec;

bool inc(int x,int b){
	int sum = x;
	while(!vec.empty() && vec.back().first == b - 1){
		sum--;
		vec.pop_back();
	}
	if(vec.empty()) return false;
	if(vec.back().first != 0 || vec.back().second == 1) vec.back().first++;
	else{
		vec.back().second--;
		vec.emplace_back(1,1);
	}
	if(x != sum) vec.emplace_back(0,x - sum);
	return true;
}

bool isOK(int b){
	vec.clear();
	for(int i = 0;i < n;i++){
		if(a[i] == a[i + 1]){
			if(!inc(a[i + 1],b)) return false;
		}else if(a[i] < a[i + 1]){
			vec.emplace_back(0,a[i + 1] - a[i]);
		}else{
			int sum = a[i];
			while(sum > a[i + 1]){
				sum -= vec.back().second;
				vec.pop_back();
			}
			if(a[i + 1] != sum) vec.emplace_back(0,a[i + 1] - sum);
			if(!inc(a[i + 1],b)) return false;
		}
	}
	return true;
}

signed main(){
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i + 1];
	int ng = 0,ok = n;
	while(ok - ng > 1){
		int mid = (ok + ng) / 2;
		if(isOK(mid)) ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
}
