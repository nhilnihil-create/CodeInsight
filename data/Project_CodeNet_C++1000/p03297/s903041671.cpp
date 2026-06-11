#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define int long long
using namespace std;
typedef pair<int, int> P;
const int INF = 1e15;

int gcd(int a, int b){
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a % b);
}

signed main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a < b) cout << "No" << endl;
        else if(b > d) cout << "No" << endl;
        else if(b <= c) cout << "Yes" << endl;
        else{
            int MAX = a % b + (b - a % b - 1) / gcd(b, d) * gcd(b, d);
            // int MAX = b - max(gcd(b, d), ((b - a % b) % gcd(b, d)));
            if(c + 1 <= MAX && MAX < b) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
}