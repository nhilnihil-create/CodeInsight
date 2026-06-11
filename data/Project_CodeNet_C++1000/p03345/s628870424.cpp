#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'
#define int long long
#define P pair<int,int>


signed main() {
    int a,b,c,k;
    cin >> a >> b >> c >> k;

    int ans = 0;
    if(k % 2 == 0){
        cout << a - b << endl;
    } else {
        cout << b - a << endl;
    }
}