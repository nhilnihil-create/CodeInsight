#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000000

long long int par[MAX_N]; //親
long long int Rank[MAX_N]; //木の深さ
long long int Size[MAX_N];

void init(long long int n){
    for(int i=0;i<n;i++){
        par[i] = i;
        Rank[i] = 0;
        Size[i] = 1;
    }
}

long long int find(long long int x){
    if(par[x] == x){
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

void unite(long long int x, long long int y){
    x = find(x);
    y = find(y);

    if(x==y){
        return;
    }

    if(Rank[x] < Rank[y]){
        par[x] = y;
        Size[y] += Size[x];
    }else{
        par[y] = x;
        Size[x] += Size[y];
        if(Rank[x] == Rank[y]){
            Rank[x]++;
        }
    }
}

bool same(long long int x, long long int y){
    return find(x) == find(y);
}

long long int size(long long int x){
    return Size[find(x)];
}

int main(){
    long long int N,M,sub=0;
    cin >> N >> M;
    init(N);
    vector<pair<int,int>> edge(M);
    vector<long long int> ans(M);

    for(int i=0;i<M;i++){
        cin >> edge[M-1-i].first >> edge[M-1-i].second;
        edge[M-1-i].first--;
        edge[M-1-i].second--;
    }

    ans[M-1] = N*(N-1)/2;

    for(int i=0;i<M-1;i++){
        int A,B;
        A = edge[i].first;
        B = edge[i].second;
        
        if(!same(A,B)){
            sub += size(A)*size(B);
            unite(A,B);
        }

        ans[M-2-i] = N*(N-1)/2 - sub;
    }

    for(int i=0;i<M;i++){
        cout << ans[i] << endl;
    }
}