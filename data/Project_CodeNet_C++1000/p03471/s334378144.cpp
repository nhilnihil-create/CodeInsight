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
    int n, y;
    cin >> n >> y;
    for(int i=0; i<=n; ++i){
        for(int j=0; j<=n; ++j){
            if(10000*i + 5000*j + (n-i-j)*1000 == y && n-i-j >=0){
                printf("%d %d %d", i, j, n-i-j);
                return 0;
            }
        }
    }
    cout << "-1 -1 -1";
}