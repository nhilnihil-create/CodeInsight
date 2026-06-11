#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define read_input         freopen("in.txt","r", stdin)
#define print_output       freopen("out.txt","w", stdout)
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int L, e = 0;
    vector<pii> adj[30];

    cin >> L;
    int p = 0;
    while(1<<(p+1) <= L) p++;


    for(int i = 1; i <= p; i++, e += 2) {
        adj[i].pb({i+1, 0});
        adj[i].pb({i+1, 1<<(i-1)});
    }

    if(L - (L & -L)) {
        int k = L, cnt = 1, sum = 1 << p; e--;
        while(k) {
            if(k & 1) adj[cnt].pb({p+1, sum}), sum += 1 << (cnt - 1);
            e += (k & 1);
            k /= 2; cnt++;
        }
    }

    cout << p+1 << " " << e << endl;
    for(int i = 1; i <= p; i++) {
        for(auto it : adj[i])
            cout  << i << " " << it.first << " " << it.second << endl;
    }
    return 0;

}
