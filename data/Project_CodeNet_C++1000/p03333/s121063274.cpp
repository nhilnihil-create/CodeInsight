#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int L[100005], R[100005];
priority_queue<pair<int, int>> pq[2];
int used[100005];

long long trial(int state){
    int cur = 0;
    long long res = 0;
    while(!pq[state].empty()){
        int x = pq[state].top().first;
        int ind = pq[state].top().second;
        if(state == 0) x = -x;
        pq[state].pop();
        if(used[ind]) continue;
        used[ind] = 1;
        state = !state;
        if(state == 1 && x > cur) continue;
        else if(state == 0 && x < cur) continue;
        res += abs(cur-x);
        cur = x;
    }
    res += abs(cur);
    return res;
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d%d", &L[i], &R[i]);
        pq[0].push({-R[i], i});
        pq[1].push({L[i], i});
    }
    long long res = trial(0);
    for(int i=0; i<N; i++){
        used[i] = 0;
        pq[0].push({-R[i], i});
        pq[1].push({L[i], i});
    }
    res = max(res, trial(1));
    printf("%lld", res);
    return 0;
}
