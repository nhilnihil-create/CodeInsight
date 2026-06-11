#include <algorithm>
#include <cassert>
// #include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
// #include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);
*/
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii;
typedef pair<int, ppiipii> pippiipii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> ppiii;
typedef pair<int, ppiii> pippiii;
typedef pair<int, ll> pill;
typedef pair<int, double> pid;
typedef pair<string, string> pss;
// note to self, the below two triggers someone
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef long double ld;

vector<pii> edges[100005];
bool seen[100005];
ll dist[100005];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b, d;
        scanf("%d%d%d", &a, &b, &d);
        edges[a].push_back(pii(b, d));
        edges[b].push_back(pii(a, -d));
    }
    for(int i = 0; i < n; i++) {
        if(seen[i]) continue;
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(pii out: edges[curr]) {
                if(!seen[out.first]) {
                    dist[out.first] = dist[curr] + out.second;
                    seen[out.first] = true;
                    q.push(out.first);
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(pii out: edges[i]) {
            if(dist[out.first] != dist[i] + out.second) {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
}
