#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef pair<int, int> P;

int main(){
    int n;
    scanf("%d", &n);
    set<P> red;
    vector<P> blue(n);
    rep(i, n){
        int x, y;
        scanf("%d %d", &x, &y);
        red.insert(P(x, y));
    }
    rep(j, n){
        scanf("%d %d", &blue[j].first, &blue[j].second);
    }
    sort(blue.begin(), blue.end());
    int ans = 0;
    for(P b : blue){
        P maxa = P(-1, -1);
        for(P r : red){
            if(r.first >= b.first) continue;
            if(r.second >= b.second) continue;
            if(maxa.second < r.second) maxa = r;
        }
        if(maxa != P(-1, -1)){
            ans++;
            red.erase(maxa);
        }
    }
    printf("%d\n", ans);
    return 0;
}