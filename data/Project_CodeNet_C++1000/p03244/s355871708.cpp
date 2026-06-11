#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    int n; cin >> n;
    V<P<int, int> > od(100010), ev(100010);
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        if(i & 1){
            od[v].first++;
            od[v].second = v;
        }else{
            ev[v].first++;
            ev[v].second = v;
        }
    }

    sort(ALL(od), greater<P<int, int>>());
    sort(ALL(ev), greater<P<int, int>>());

    int t = 0;
    if(od[0].second == ev[0].second){
        t = max(od[0].first + ev[1].first, od[1].first + ev[0].first);
    }else{
        t = od[0].first + ev[0].first;
    }
    cout << n - t << endl;

    return 0;
}
