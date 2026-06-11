#include<bits/stdc++.h>
using namespace std;

#define LL long long
int h, w, d, a, x[100005], y[100005], l, r, q, dis[100005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> h >> w >> d;
    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= w; j++) {
            cin >> a;
            x[a] = i, y[a] = j;
        }

    for(int i = d + 1; i <= h * w; i++) dis[i] = dis[i-d] + abs(x[i] - x[i-d]) + abs(y[i] - y[i-d]);

    cin >> q;
    while(q--) {
        cin >> l >> r;
        cout << dis[r] - dis[l] << '\n';
    }        
}