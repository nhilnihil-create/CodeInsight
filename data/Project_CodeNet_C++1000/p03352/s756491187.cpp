#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int x;
    cin >> x;
    int ans = 1;
    for(int i = 2; i*i <= x; ++i){
        for(int j = i*i; j <= x; j*=i){
            ans = max(ans, j);
        }
    }
    cout << ans << endl;
    return 0;
}