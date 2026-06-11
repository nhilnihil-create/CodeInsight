#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
template<typename T>
void print(T x) {
    cout << x << endl;
}
int main(void) {
    int n, h, w;
    cin >> n >> h >> w;
    int ans = (n - h + 1) * (n - w + 1);
    cout << ans;
}

