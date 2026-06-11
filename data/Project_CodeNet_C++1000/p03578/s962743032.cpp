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
    map<int, int> m, t;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        ++m[x];
    }
    int p;
    cin >> p;
    for(int i=0; i<p; ++i){
        int x;
        cin >> x;
        ++t[x];
    }

    for(auto x:t){
        if(x.second > m[x.first]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
