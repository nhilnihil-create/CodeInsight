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
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
    }

    n = n-k;
    cout << 1 + (n+k-2)/(k-1);
}