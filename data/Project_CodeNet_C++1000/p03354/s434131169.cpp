#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define itn int
#define P pair<int,int>
#define rep2(i,a,n) for(int i = (a);i < (n);i++)
#define rep(i,n) rep2(i,0,n)

int n,m;
vector<int> par(200000);

int root(int x){
    if(par[x] == x)return x;
    return par[x] = root(par[x]);
}

void unite(int x,int y){
    x = root(x),y = root(y);
    if(x == y)return;
    par[x] = y;
}

int main(void){
    cin >> n >> m;
    
    int p[n],x[m],y[m];
    for(int i = 0;i < n;i++){
        cin >> p[i];p[i]--;
        par[i] = i;
    }
    
    for(int i = 0;i < m;i++){
        cin >> x[i] >> y[i];
        unite(x[i]-1,y[i]-1);
    }
    
    int alina = 0;
    for(int i = 0;i < n;i++){
        if(root(i) == root(p[i]))alina++;
    }
    cout << alina << endl;
}