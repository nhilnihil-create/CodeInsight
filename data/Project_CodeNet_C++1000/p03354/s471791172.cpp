#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

#define S 10000000
int par[S];
int  r[S];

void init(int n){
    for(int i = 0;i < n;i++){
        par[i] = i;
        r[i] = 0;
    }

}

//calculate tree's root
int find(int x){
    if(par[x] == x){
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

//union x-set and y-set
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return ;

    if(r[x] < r[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(r[x] == r[y]) r[x]++;
    }
}

bool same(int x, int y){
    return find(x) == find(y);
}

int main(){
    int n, m;
    cin >> n >> m;
    int p[n];
    for(int i = 0;i < n;i++) cin >> p[i];
    int x[m],y[m];
    for(int i = 0;i < m;i++){
        cin >> x[i] >> y[i];
    }
    init(n);

    for(int i = 0;i < m;i++){
        unite(x[i]-1, y[i]-1);
    }

    int ans = 0;
    for(int i = 0;i < n;i++){
        if(same(i, p[i]-1)) ans++;
    }
    cout << ans << endl;


}