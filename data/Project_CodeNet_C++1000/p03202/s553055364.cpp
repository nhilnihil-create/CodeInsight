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

int n, v[Nmax], sz, mx;
map<int,int> M;

bool solve(int x){
    // dbg(x,sz);
    if (x <= sz){
        if (mx == 0) return 0;
        while (!M.empty() && prev(M.end())->first > sz){
            M.erase(prev(M.end()));
        }
        sz = x;
        M[sz]++;
        int i = sz;
        while (M[i] > mx){
            // dbg(x,i,mx);
            if (i==1)
                return 0;
            M[i] = 0;
            M[i-1]++;
            i--;
        }
        return 1;
    }
    else{
        sz = x;
        return 1; 
    }
    return 0;
}

bool OK(int x){
    mx = x;
    M.clear(); sz = 0;
    for(int i=1;i<=n;i++){
        if (!solve(v[i])){
            return 0;
        }
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> v[i];
    }

    int st = 0, p = 1;
    for (;p<=n;p<<=1);
    for (;p>=1;p>>=1){
        if (st + p <= n && !OK(st+p)){
            st += p;
        }
    }

    if (!OK(st)) st++;
    cout << st + 1 << '\n';


    return 0;
}