#include <bits/stdc++.h>
using namespace std;

const int L = 31;

vector<int> v[L][2][2];
int n, r;

void g(int t){
    for(int i = 0, x; i < n; i++){
        scanf("%d", &x);
        for(int j = 0, k = 0; j < L; j++){
            int y = x & (1 << j);
            v[j][t][!!y].push_back(k);
            k |= y;
        }
    }
}

int f(int x, int y, int z){
    auto &w = v[x][0][y], &u = v[x][1][z];
    int r = ~(y ^ z) & w.size() & u.size() & 1;
    for(int i = 0, j = int(u.size()) - 1; i < w.size(); i++){
        for(; j >= 0 && w[i] + u[j] >= (1 << x); j--);
        if(j < 0) return r & 1;
        r ^= ~j;
    }
    return r & 1;
}

int main(){
    scanf("%d", &n);
    g(0);
    g(1);
    for(int i = 0; i < L; i++){
        for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++)
            sort(v[i][j][k].begin(), v[i][j][k].end());
        r |= (f(i, 0, 0) ^ f(i, 0, 1) ^ f(i, 1, 0) ^ f(i, 1, 1)) << i;
    }
    printf("%d\n", r);
}