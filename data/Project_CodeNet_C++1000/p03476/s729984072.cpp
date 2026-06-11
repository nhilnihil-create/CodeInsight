#include <bits/stdc++.h>

#define FOR(i, l, r) for(long long int i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)

#define MOD 1000000007
#define INF 1000000000

using ll = long long int;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int Q; cin >> Q;

    //エラトステネスの篩
    int MXN = 101010; 
    vector<bool> num(MXN, true);
    num[0] = false; num[1] = false;
    for(ll i = 2; i * i <= MXN; i++) {
        if(num[i]){
            for(ll j = i*i; j <= MXN; j += i) num[j] = false;
        }
    }
    
    vector<int> ans(MXN, 0);
    rep(i,MXN-10){
        if(i%2 == 0) {
            ans[i] = 0;
            continue;
        }
        if(num[i] && num[(i+1)/2]) ans[i]++;
        if(i >= 2) ans[i] += ans[i-2];
    }

    queue<int> que;
    rep(i,Q){
        int l,r;
        cin >> l >> r;
        que.push( ans[r] - ans[max(l-2,0)] );
    }

    while(!que.empty()) {
        cout << que.front() << "\n";
        que.pop();
    }
    return 0;
}
