#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <functional>
#include <map>
#include <set>
#define REP(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define INF 10000000
#define ll long long

using namespace std;

typedef pair<int, int> P;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int K;
int d[100000];

int main(){
    scanf("%d", &K);

    REP(i, K) d[i] = INF;
    d[1] = 1;

    deque<int> que;
    que.push_back(1);

    while(!que.empty()){
        int t = que.front(); que.pop_front();
        if(t == K) continue;

        int a = (t + 1) % K;
        int b = (t * 10) % K;

        if(d[t] + 1 < d[a]){
            d[a] = d[t] + 1;
            que.push_back(a);
        }
        if(d[t] < d[b]){
            d[b] = d[t];
            que.push_front(b);
        }
    }

    printf("%d", d[0]);

	return 0;
}