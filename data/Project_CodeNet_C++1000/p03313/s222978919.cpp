#include <bits/stdc++.h>
using namespace std;

#define ris   return *this
#define tmplt template<class T
#define dbgo  debug& operator<<
tmplt > struct rge { T b, e; };
tmplt > rge<T> range(T i, T j) { return rge<T>{i, j}; }
struct debug {
#ifdef LOCAL
~debug(){cerr<<endl;}
tmplt > dbgo(T x){cerr<<boolalpha<<x;ris;}
tmplt, class C > dbgo(pair<T, C> x){ris<<"("<<x.first<<", "<<x.second<<")";}
tmplt > dbgo(rge<T> x){*this<<"[";for(auto it=x.b;it!=x.e;it++){*this<<", "+2*(it==x.b)<<*it;}ris<<"]";}
tmplt > dbgo(vector<T> x){ris<<range(x.begin(),x.end());}
#else
tmplt > dbgo(const T&){ris;}
#endif
};
#define nav(...) << "[ " << #__VA_ARGS__ ": " << (__VA_ARGS__) << " ] "
using ll = long long;

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define ford(i, n) for(int i = n-1; i >= 0; i--) 

template<typename T> 
void min_self(T& a, T b) { 
    a = min(a, b); 
}
template<typename T>
void max_self(T& a, T b) { 
    a = max(a, b); 
}

void merge(pair<pair<int,int>,pair<int,int>>& a, pair<int,int> b) {
    if(b == a.first) {
        return;
    }
    if(b > a.first) {
        a.second = a.first;
        a.first = b;
    } else if(b > a.second) {
        a.second = b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int,int>> a(1<<n);
    forn(i, 1<<n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    vector<pair<pair<int,int>,pair<int,int>>> dp(1<<n);
    
    for(int i = 1; i < (1<<n); i++) {
        pair<int,int> x, y;
        x = a[i], y = a[0];
        if(x < y) swap(x, y);
        dp[i] = make_pair(x, y);
        for(int b = 0; b < n; b++) {
            if(i>>b&1) {
                int j = i ^ (1<<b);
                merge(dp[i], dp[j].first);
                merge(dp[i], dp[j].second);
            }
        }
    }
    
    vector<int> ans(1<<n);
    for(int i = 1; i < (1<<n); i++) {
        ans[i] = dp[i].first.first + dp[i].second.first;
        max_self(ans[i], ans[i-1]);
        cout << ans[i] << '\n';
    }
}













// Don't worry, you're getting better

// Read statement carefully
// Solve on paper first!
// Make your infinity big enough
// Overflows (long long)

// Author: blondie
