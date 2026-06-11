#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl "\n"
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    ll sa=0, sb=0;
    for(int i=0; i<n; ++i)
        cin >> a[i], sa+=a[i];

    for(int i=0; i<n; ++i)
        cin >> b[i], sb+=b[i];
    
    if(sa<sb){
        cout << -1;
        return 0;
    }

    ll rs=0, ans=0;
    vector<int> gs;
    for(int i=0; i<n; ++i){
        if(a[i]<b[i])
            rs+=b[i]-a[i], ans++;
        
        if(a[i] > b[i])
            gs.push_back(a[i]-b[i]);
    }
    sort(all(gs), greater<int> ());

    for(auto x: gs){
        if(rs > 0){
            ans++;
            rs -= x;
        }
        else
            break;
    }
    cout << ans;
}