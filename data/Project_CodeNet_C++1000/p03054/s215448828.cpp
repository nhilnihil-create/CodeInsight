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

int n,m,k,x,y,L,R,U,D;
string A,B;

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    cin >> x >> y;
    cin >> A >> B;

    for (int i=k-1;i>=0;i--){
        if (B[i]=='U') D = max(D-1,0);
        if (B[i]=='D') U = max(U-1,0);
        if (B[i]=='L') R = max(R-1,0);
        if (B[i] == 'R') L = max(L-1,0);
    
        if (A[i] == 'U') U++;
        if (A[i] == 'D') D++;
        if (A[i] == 'R') R++;
        if (A[i] == 'L') L++;

        if (L + R >= m || U + D >= n){
            cout << "NO\n";
            return 0;
        }
    }

    if (U >= x || x + D > n){
        cout << "NO\n";
        return 0;
    }
    if (L >= y || y + R > m){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}