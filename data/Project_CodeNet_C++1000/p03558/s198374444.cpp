#include <iostream>
#include <algorithm>
#include <queue>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int k, i, d[100003] = {}, ds, pv, nv;
    priority_queue<P, vector<P>, greater<P>> pq;

    scanf("%d", &k);

    for (i = 0; i < k; i++) {
        d[i] = INF;
    }

    for (i = 1; i < 10; i++) {
        if (d[i % k] > i) {
            d[i % k] = i;
            pq.push(P(i, i % k));
        }
    }

    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        ds = p.first;
        pv = p.second;
        if (d[pv] < ds) {
            continue;
        }
        for (i = 0; i < 10; i++) {
            nv = (pv * 10 + i) % k;
            if (d[nv] > ds + i) {
                d[nv] = ds + i;
                pq.push(P(d[nv], nv));
            }
        }
    }

    printf("%d\n", d[0]);

    return 0;
}