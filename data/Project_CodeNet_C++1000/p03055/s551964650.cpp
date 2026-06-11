#include<iostream>
#include<vector>
#define DIM 200005
using namespace std;
int n, i, x, y, nod, m;
int d[DIM], viz[DIM], s[DIM];
vector<int> v[DIM];
void dfs(int nod){
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(viz[vecin] == 0){
            d[vecin] = 1 + d[nod];
            dfs(vecin);
        }
    }
}
int main(){
    cin>> n;
    for(i = 1; i < n; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    s[1] = 1;
    for(i = 3; i <= n; i++){
        if(s[i - 1] == 0 || s[i - 2] == 0){
            s[i] = 1;
        }
    }
    dfs(1);
    for(i = 1; i <= n; i++){
        if(d[i] > d[nod]){
            nod = i;
        }
    }
    for(i = 1; i <= n; i++){
        d[i] = viz[i] = 0;
    }
    dfs(nod);
    for(i = 1; i <= n; i++){
        m = max(m, d[i]);
    }
    if(s[m + 1] == 1){
        cout<<"First";
    }
    else{
        cout<<"Second";
    }
}
