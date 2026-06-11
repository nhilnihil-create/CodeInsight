#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    for(int i = a; i <= b; ++i) {
        if(i<a+k) {cout << i << endl; continue; }
        if(b-i<k) cout << i << endl;
    }
    return 0;
}   