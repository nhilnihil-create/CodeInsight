#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001

int main() {
    int n,h;cin >> n >> h;
    vector<int> b(n);
    int m=0;
    for(int i = 0; i < n; i++) {
        int x,y;cin >> x >> y;
        m=max(m,x);
        b[i]=y;
    }
    vector<int> c;
    for(int i = 0; i < n; i++) {
        if(b[i]>m) c.push_back(b[i]);
    }
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    int ans=0;

    for(int i = 0; i < c.size(); i++) {
        h -= c[i];
        ans++;
        if(h<=0) break;
    }
    if(h>0){
        h--;
        h /= m;
        ans += h;
        ans++;
    }

    cout << ans << endl;

    return 0;
}