#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define outmat(v) for(auto i : v){for(auto j : i) cout << j << " ";cout << endl;}
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
#define infi 1900000000
#define infl 1100000000000000000
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
#define csp << " " <<
#define outset(n) cout << fixed << setprecision(n);
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> using ve = vector<T>;
template<typename T> using pq2 = priority_queue<T>;
template<typename T> using pq1 = priority_queue<T,vector<T>,greater<T>>;




int main()
{
    string S;
    cin >> S;
    int N = int(S.length());
    
    S+="2";
    
    char fnow = S[0];
    int leak = 0;
    int left = 0;
    ve<pii> A;
    rep(i,N+1){
        if(fnow == S[i]){
            leak++;
        }else{
            A.pb({left,leak});
            left += leak;
            leak = 1;
            fnow = S[i];
        }
    }
    
    int n = int(A.size());
    
    int ans = infi;
    int an = infi;
    for (int i = 0; i < n; i+=2) {
        int a = min(A[i].fi+A[i].se,N-A[i].fi);
        int b = max(A[i].fi,N-A[i].se-A[i].fi);
        an = min(an,max(a,b));
    }
    ans = an;
    for (int i = 1; i < n; i+=2) {
        int a = min(A[i].fi+A[i].se,N-A[i].fi);
        int b = max(A[i].fi,N-A[i].se-A[i].fi);
        an = min(an,max(a,b));
    }
    ans = max(ans,an);
    
    out(ans);
    
    
    

    return 0;
}
