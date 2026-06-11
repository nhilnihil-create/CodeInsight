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

const int inf = 1e9+5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    forn(i, n) {
        cin >> a[i];
    }
    int ans = inf;
    forn(i, n) {
        int split = a[i];
        vector<int> cur, seg;
        forn(j, n) {
            if(a[j] < split) {
                int m = seg.size();
                sort(seg.begin(), seg.end());
                forn(p, m-k+1) {
                    cur.push_back(seg[p]);
                }
                seg.clear();
            } else {
                seg.push_back(a[j]);
            }
        }
        int m = seg.size();
        sort(seg.begin(), seg.end());
        forn(j, m-k+1) {
            cur.push_back(seg[j]);
        }
        
        sort(cur.begin(), cur.end());
        if((int) cur.size() < q) continue;
        debug() nav(split) nav(cur);
        min_self(ans, cur[q-1]-cur[0]);
    }
    
    cout << ans << endl;
}













// Don't worry, you're getting better

// Read statement carefully
// Solve on paper first!
// Make your infinity big enough
// Overflows (long long)

// Author: blondie
