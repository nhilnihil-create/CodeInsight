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
#define Nmax 500005
const long double PI = acos(-1);

int mx, n, x, y, sav, DP[Nmax];
vector<int> v[Nmax];

void dfs(int nod, int h, int ant){
    if (h > mx){
        mx = h;
        sav = nod;
    }
    for (auto it : v[nod]){
        if (it == ant) continue;
        dfs(it, h+1, nod);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=1;i<n;i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1,1,-1);
    mx = 0;
    dfs(sav,1,-1);

    DP[1] = 1;
    DP[2] = 0;
    DP[3] = 1;
    for (int i=4;i<=mx;i++){
        if (DP[i-1] == 0 || DP[i-2] == 0) DP[i] = 1;
    }

    if (DP[mx]) cout << "First\n";
    else cout << "Second\n";

    return 0;
}