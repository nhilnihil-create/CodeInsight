#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

int N;
int A[1<<18];
priority_queue<pair<int,int>> pq[1<<18];

signed main(){
    cin >> N;
    rep(i, 1<<N) cin >> A[i];

    int ans = 0;
    rep(i, 1<<N){
        pq[i].push({ A[i],i });
        pair<int,int> m = pq[i].top();
        pq[i].pop();
        while(!pq[i].empty() && pq[i].top() == m) pq[i].pop();
        if(!pq[i].empty()) ans = max(ans, m.first+pq[i].top().first);
        if(i != 0) cout << ans << endl;

        int k = 0;
        while(i >= (1<<k)) k++;
        for(int j=i+(1<<k); j<(1<<N); j+=(1<<k)){
            pq[j].push(m);
            if(!pq[i].empty()) pq[j].push(pq[i].top());
        }
        for(int j=0; j<k; j++){
            if(((i>>j)&1) == 0){
                pq[i+(1<<j)].push(m);
                if(!pq[i].empty()) pq[i+(1<<j)].push(pq[i].top());
            }
        }
    }
}