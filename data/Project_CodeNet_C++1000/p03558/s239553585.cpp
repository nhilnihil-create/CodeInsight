#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define FOR(i,S,E) for(int i=S; i<E; i++)
#define ri(x) scanf("%d", &x)
#define fst first
#define snd second

const int MAXK = 1e5+10;
int K, vis[MAXK];
int main() {
    ri(K);
    deque<ii> dq;
    dq.push_back({1, 0});
    while(dq.size()) {
        ii u = dq.front();
        dq.pop_front();
        if (u.fst == 0) {
            printf("%d\n", u.snd+1);
            return 0;
        }
        vis[u.fst] = true;
        if (!vis[(u.fst+1)%K])
            dq.push_back({(u.fst+1)%K, u.snd+1});
        if (!vis[(u.fst*10)%K])
            dq.push_front({(u.fst*10)%K, u.snd});
    }
}
