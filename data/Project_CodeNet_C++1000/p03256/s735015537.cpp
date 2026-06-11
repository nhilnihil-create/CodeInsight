#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define MOD 1000000007
#define zeros(x) x&(x-1)^x
#define fi first
#define se second
#define Nmax 200005
const long double PI = acos(-1);


int n, m, nrR[Nmax], nrB[Nmax], uz[Nmax];
vector<int> v[Nmax];
string s;

void read(){
	cin >> n >> m;
	cin >> s;
	for (int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
		if (s[y-1] == 'A') nrR[x]++;
		else nrB[x]++;
		if (s[x-1] == 'A') nrR[y]++;
		else nrB[y]++;
	}
}

bool OK(int nod){
	return nrB[nod] && nrR[nod];
}

void update(int nod, char c){
	if (c == 'A') nrR[nod]--;
	else nrB[nod]--;
}

int Q[Nmax], lg = 0, cnt = 0;
void elim(){
	cnt = n;
	for (int i=1;i<=n;i++){
		if (!OK(i)){
			cnt--;
			uz[i] = 1;
			Q[++lg] = i;
		}
	}
	while (lg && cnt){
		int crt = Q[lg--];
		for (auto it : v[crt]){
			if (uz[it]) continue;

			update(it, s[crt-1]);
			if (!OK(it)){
				Q[++lg] = it;
				uz[it] = 1;
				cnt--;
			}
		}
	}

	cout << (cnt ? "Yes\n" : "No\n");
}


int main(){
    ios::sync_with_stdio(false);
    
    read();
    elim();

    return 0;
}