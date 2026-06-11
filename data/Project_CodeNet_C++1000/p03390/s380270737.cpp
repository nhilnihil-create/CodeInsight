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

void test_case() {
    
    ll a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);
    if(b - a <= 1) {
        cout << 2*a-2 << '\n';
    } else {
        ll p = a*b-1;
        ll lo = 0, hi = b;
        while(lo < hi) {
            ll mid = lo + (hi - lo + 1)/2;
            if(mid*mid < p+1) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        if(lo * (lo+1) >= p+1) {
            cout << 2*lo-2 << '\n';
        } else {
            cout << 2*lo-1 << '\n';
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--) {
        test_case();
    }
}













// Don't worry, you're getting better

// Read statement carefully
// Solve on paper first!
// Make your infinity big enough
// Overflows (long long)

// Author: blondie
