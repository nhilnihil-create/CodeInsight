#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) (1 + (int)((a) - 1)/(int)(b))
//#define int long long

signed main(){
    int n; cin >> n;
    vector<int> place(n+2), dist(n+2);
    
    place[0] = place[n+1] = dist[0] = 0;
    rep(i,n){
        cin >> place[i+1];
        dist[i+1] = dist[i] + abs(place[i+1] - place[i]);
    }
    
    dist[n+1] = dist[n] + abs(place[n]);
    
    reps(i, 1, n){
        int d = dist[n+1];
        d -= dist[i+1] - dist[i-1];
        d += abs(place[i+1] - place[i-1]);
        cout << d << endl;
    }
}