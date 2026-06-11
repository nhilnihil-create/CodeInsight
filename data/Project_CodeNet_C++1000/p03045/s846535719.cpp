#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int inf = 100000000;
int MAX_N = 100005;
vector<int> par(MAX_N ,inf);
vector<int> Rank(MAX_N);

void init(int n){
    for(int i=0;i<n;i++){
        par[i] = i;
        Rank[i] = 0;
    }
}

int find(int x){
    if(par[x] == x){
        return x;
    }else {
        return par[x] = find(par[x]);
    }
}

void unite(int x ,int y){
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(Rank[x] < Rank[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(Rank[x] == Rank[y]) Rank[x]++;
    }
}

bool same(int x ,int y){
    return find(x) == find(y);
}

int main(){
    int n,m;
    cin >> n >> m;
    init(n);
    for(int i=0;i<m;i++){
        int x,y,z;
        cin >> x >> y >> z;
        x--;y--;
        unite(x ,y);
    }


    int sum = 0;
    for(int i=0;i<n;i++){
        if(i == par[i]) sum++;
    }

    cout << sum << endl;
}