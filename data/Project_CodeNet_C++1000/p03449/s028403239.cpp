#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    for(int i=0; i<n; ++i){
        cin >> b[i];
    }

    vector<int> p(n), s(n);
    p[0] = a[0];
    s[n-1] = b[n-1];
    for(int i=1; i<n; ++i){
        p[i] = a[i]+p[i-1];
    }
    for(int i=n-2; i>=0; --i){
        s[i] = b[i]+s[i+1];
    }

    int ans = 0;
    for(int i=0; i<n; ++i){
        ans = max(ans, p[i]+s[i]);
    }
    cout << ans;
}
