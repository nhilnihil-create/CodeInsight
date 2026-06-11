#include <bits/stdc++.h>
using namespace std;

const int N = 2005, inf = int(2e9);
int n, a[N], q, k, p[N], c[N], r = inf;

int main(){
    scanf("%d%d%d", &n, &k, &q);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    iota(p + 1, p + n + 1, 1);
    sort(p + 1, p + n + 1, [](int x, int y){ return a[x] < a[y]; });
    c[n + 1] = 1;
    for(int t = 1; ; t++){
        priority_queue<int, vector<int>, greater<int>> pq, ppq;
        for(int i = 1; i <= n + 1; i++){
            if(c[i]){
                while(!pq.empty()){
                    if(pq.size() >= k) ppq.push(pq.top());
                    pq.pop();
                }
            }
            else pq.push(a[i]);
        }
        if(ppq.size() < q) break;
        int mn = ppq.top();
        for(int i = 0; i < q - 1; i++) ppq.pop();
        r = min(r, ppq.top() - mn);
        c[p[t]] = 1;
    }
    printf("%d\n", r);
}