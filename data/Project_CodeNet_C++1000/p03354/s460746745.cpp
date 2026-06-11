#include <bits/stdc++.h>
using namespace std;
const int max_n = 100000+5;
int n, W,L,P,k,m;
static long  dp[101][max_n];
long  x[max_n],y[max_n],p[max_n],X[max_n],T[max_n],ppar[max_n],rrank[max_n];
void init(int n){
    for(int i=0 ; i<n ; i++){
        ppar[i] = i;
        rrank[i] = 0;
    }
}
int find(int x){
    if(ppar[x] == x){
        return x;
    }else{
        return ppar[x] = find(ppar[x]);
    }
}
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)  return;

    if(rrank[x] < rrank[y]){
        ppar[x] = y;
    }else{
        ppar[y] = x;
        if(rrank[x] == rrank[y])  rrank[x]++;
    }
}
bool same(int x, int y){
    return find(x) == find(y);
}
void solve(){
}

int main(){
    int count = 0;
    cin >> n >> m;
    init(n);
    for(int i=0 ; i<n ; i++){
        cin >> p[i];
        p[i]--;
    }
    for(int i=0 ; i<m ; i++){
        cin >> x[i] >> y[i];
        unite(--x[i], --y[i]);
    }
    for(int i=0 ; i<n ; i++){
        if(same(p[i], i)){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
