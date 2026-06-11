#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int SH = 1e5 + 7, N = SH << 1;
int n;
int l[N], r[N];

void calc(int a[N]) {
    for (int i = 1; i < N; ++i)
        a[i] += a[i - 1];
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        a += SH; b += SH;
        ++l[a];
        ++r[b];
    }   

    calc(l); calc(r);

    int ans = 0;
    for (int i = SH; i + 1 < N; ++i) {
        int inl = r[i] + 1;
        int inr = n - l[i];
        ans += min(inl, inr) * 2;        
    }   
    for (int i = SH; i; --i) {
        int inl = r[i - 1];
        int inr = n - l[i - 1] + 1;
        ans += min(inl, inr) * 2;
    }   
    cout << ans << endl;
}