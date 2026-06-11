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

int calc(vector<int> a, vector<int> b, int bit) {
    int n = a.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    debug() nav(a);
    debug() nav(b);
    ll ans = 0;
    int target = 1<<bit;
    for(int i = 0; i < n; i++) {
        int r = lower_bound(b.begin(), b.end(), 2*target - a[i]) - b.begin();
        r--;
        int l = lower_bound(b.begin(), b.end(), target - a[i]) - b.begin();
        //$ debug() nav(l) nav(r);
        ans += r - l + 1;
        l = lower_bound(b.begin(), b.end(), 3*target - a[i]) - b.begin();
        ans += n - l;
    }
    
    return ans & 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int ans = 0;
    for(int bit = 0; bit < 30; bit++) {
        vector<int> na(n), nb(n);
        for(int i = 0; i < n; i++) {
            na[i] = a[i] % (1<<(bit+1));
            nb[i] = b[i] % (1<<(bit+1));
        }
        //$ debug() nav(bit) nav(calc(na, nb, bit));
        ans |= calc(na, nb, bit)<<bit;
    }
    
    cout << ans << endl;
}













// Don't worry, you're getting better

// Read statement carefully
// Solve on paper first!
// Make your infinity big enough
// Overflows (long long)

// Author: blondie
