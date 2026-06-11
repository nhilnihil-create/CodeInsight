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
    int n, x;
    cin >> n >> x;
    vector<int> a;

    a.push_back(x);
    for(int i=0; i<n; ++i){
        int l;
        cin >> l;
        a.push_back(l);
    }
    sort(all(a));

    if(n==1){
        cout << gcd(0, a[1]-a[0]);
        return 0;
    }


    vector<int> z;
    for(int i=1; i<=n; ++i){
        z.push_back(a[i]-a[i-1]);
    }

    int ans=0;
    for(int i=0; i<n; ++i)
        ans = gcd(ans, z[i]);
    cout << ans;
}