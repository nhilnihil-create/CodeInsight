#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
template<typename T>
void print(T x) {
    cout << x << endl;
}
int main(void) {
    int n, k; cin >> n >> k;
    int ans;
    if(n%k == 0) ans = 0;
    else ans = 1;
    cout << ans;
}
