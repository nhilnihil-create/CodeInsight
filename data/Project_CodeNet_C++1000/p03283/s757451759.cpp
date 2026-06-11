#include <iostream>
#include <algorithm>

struct LR{
    int l, r;
}lr[200000];

bool comp(LR x, LR y){
    if(x.l == y.l){
        return x.r < y.r;
    }
    return x.l < y.l;
}

int main()
{
    using namespace std;
    
    int n, m, q, pq[100000][2], ps[501][501] = {{0}};
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++){
        cin >> lr[i].l >> lr[i].r;
    }
    sort(lr, lr + m, comp);
    for(int i = 0; i < m; i++){
        ps[lr[i].l][lr[i].r]++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ps[j][i] += ps[j - 1][i];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ps[i][j] += ps[i][j - 1];
        }
    }
    for(int i = 0; i < q; i++){
        cin >> pq[i][0] >> pq[i][1];
        cout << ps[pq[i][1]][pq[i][1]] - ps[pq[i][0] - 1][pq[i][1]] << endl;
    }
    return 0;
}
