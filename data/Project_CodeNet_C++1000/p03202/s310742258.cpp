//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
 
void dout() { cerr << '\n'; }
 
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << " " << H;
    dout(T...);
}
 
#ifdef LOCAL
    #define dbg(...) cerr << #__VA_ARGS__, dout(__VA_ARGS__)
#else
    #define dbg(...) ;
#endif
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
 
const int N = 2e5 + 123;
int n, a[N];
set <pii> st;
 
void add(int pos, int x) {
    if (pos < 1) {
        return;
    }
    if (!st.empty()) {
        if ((*prev(st.end())).fi == pos) {
            return;
        }
        if ((*prev(st.end())).se == x) {
            st.erase(prev(st.end()));
        }
    }
    st.insert({pos, x});
}
 
void debug() {
    cout << "st:\n";
    for (auto i : st) {
        cout << i.fi << ' ' << i.se << '\n';
    }
    cout << '\n';
}
 
bool check(int k) {
    st.clear();
    add(a[1], 0);
    pii last;
    for (int i = 2; i <= n; i++) {
        if (a[i - 1] < a[i]) {
            add(a[i], 0);
        }   else {
            last.fi = 0;
            while (!st.empty() && (*prev(st.end())).fi >= a[i]) {
                last = *prev(st.end());
                st.erase(prev(st.end()));
            }
            last.fi = a[i];
            add(last.fi, last.se);
            last = *prev(st.end());
            if (last.se == k - 1) {
                st.erase(prev(st.end()));
                if (st.empty()) {
                    return false;
                }
                last = *prev(st.end());
                st.erase(prev(st.end()));
                last.fi--;
                add(last.fi, last.se);
                last.fi++;
                last.se++;
                add(last.fi, last.se);
                last.fi = a[i];
                last.se = 0;
                add(last.fi, last.se);
            }   else {
                st.erase(prev(st.end()));
                last.fi--;
                add(last.fi, last.se);
                last.fi++;
                last.se++;
                add(last.fi, last.se);
            }
        }
    }
    return true;
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
 
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    bool good = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i > 1 && a[i] <= a[i - 1]) {
            good = false;
        }
    }
    if (good) {
        cout << 1;
        return 0;
    }
    int l = 1, r = n;
    while (l < r - 1) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        }   else {
            l = mid;
        }
    }
    cout << r;
}