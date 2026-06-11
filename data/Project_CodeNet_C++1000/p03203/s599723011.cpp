#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using P = pair<ll,ll>;
constexpr int INF = 1<<30;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> l(h, INF);
    vector<set<int> > st(h+1); 
    for(int i=0;i<n;i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        l[x] = min(l[x], y);
        st[x].insert(y);
    }
    int ans = h, ny = 0;
    for(int i=0;i<h;i++){
        if(l[i] < ny){
            ans = i;
            break;
        }
        if(st[i+1].count(ny+1) == 0) ny++;
    }
    cout << ans << endl;
    return 0;
}
