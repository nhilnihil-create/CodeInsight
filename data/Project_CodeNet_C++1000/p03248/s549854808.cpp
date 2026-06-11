#include<bits/stdc++.h>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define rrep(i,a) for(int i=(int)a-1;i>=0;--i)
#define REP(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RREP(i,a,b) for(int i=(int)a-1;i>=b;--i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<long long> vl;
typedef std::vector<std::vector<long long>> vvl;
#define out(x) cout<<x<<"\n";
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


ll gcd(ll n, ll m) {
    ll tmp;
    while (m!=0) {
        tmp = n % m;
        n = m;
        m = tmp;
    }
    return n;
}
 
ll lcm(ll n, ll m) {
    return abs(n) / gcd(n, m)*abs(m);//gl=xy
}
 
using namespace std;

 struct UF {
	vector<int>par;//親
	vector<int>Rank;//木の深さ
    vector<int>sz;//要素数

    UF(int n){init(n);}

	//初期化
	void init(int n) {
		par.resize(n); Rank.resize(n);sz.resize(n);
		for (int i = 0; i < n; i++) {
			par[i]= i;
			Rank[i] = 0;
            sz[i]=1;
		}
	}

	//木の根を求める
	int find(int x) {
		if (par[x] == x) {
			return x;
		}
		else {
			return par[x] = find(par[x]);
		}
	}

	//xとyの属する集合を併合
	bool unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)return false;//すでに同じ集合に属している

		if (Rank[x] < Rank[y]) {//高さが小さい方を下に
			par[x] = y;
            sz[y]+=sz[x];
		}
		else {
			par[y] = x;
			if (Rank[x] == Rank[y])Rank[x]++;//同じだとrankが変わらないままになるので増やす（それ以外は大きい方のrankが採用される）
            sz[x]+=sz[y];
		}
		return true;
	}

	//xとyが同じ集合に属するかを判定
	bool same(int x, int y) {
		return find(x) == find(y);
	}

    int size(int k){//要素数を求める
        return sz[find(k)];
    }
};

void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	UF tree(n);
	vector<int> node;
	node.pb(1);
	bool ng = false;
	if((s[0]!='1')||(s[n-2]!='1'))
		ng = true;
	rep(i,n)
	{
		if(s[i]=='1'){
			if(s[n-2-i]=='1'){
				node.pb(i + 1);
			}
			else
				ng = true;
		}
	}
	if(s.back()=='1')
		ng = true;
	if(ng){
		cout << -1 << "\n";
		return;
	}
	node.pb(n);
	rep(i,node.size()-1){
		int sub = node[i + 1] - node[i];
		rep(j,sub){
			cout << node[i + 1] << " " << node[i + 1] - j - 1 << "\n";
		}
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);
    solve();
    return 0;
}
