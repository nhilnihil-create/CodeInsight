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
    int r, g, b, n;
    cin >> r >> g >> b >> n;

    int ans=0;
    for(int i=0; i<=n; ++i){
        for(int j=0; j<=n; ++j){
            if((n-r*i-g*j)/b >= 0 && (n-r*i-g*j)%b==0)
                ans++;
        }
    }
    cout << ans;
}