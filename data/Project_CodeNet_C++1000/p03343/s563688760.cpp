#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = /*1'000'000'007LL;*/ 998'244'353LL;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

int N, K, Q;
int A[2000];

int z[2000];

signed main(){
    cin >> N >> K >> Q;
    rep(i, N){
        cin >> A[i];
        z[i] = A[i];
    }
    sort(z, z+N);

    int ans = INT_MAX;
    rep(i, N){
        int g[2000];
        int siz[2000] ={};
        int k = 0;
        priority_queue<pair<int, int>> pq;
        rep(j, N){
            if(A[j] < z[i]){
                k++;
            }
            else{
                g[j] = k;
                siz[k]++;
                pq.push({ -A[j],j });
            }
        }
        int tmp = 0;
        rep(j, Q){
            while(pq.size() > 0 && siz[g[pq.top().second]] < K) pq.pop();
            if(pq.empty()){
                tmp = INT_MAX;
                break;
            }
            tmp = max(tmp, -pq.top().first);
            siz[g[pq.top().second]]--;
            pq.pop();
        }
        ans = min(ans, tmp-z[i]);
    }
    cout << ans << endl;
}