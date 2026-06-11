#include<bits/stdc++.h>
using namespace std;

int par[200000];
int n,m;

int root(int x){
    if(par[x] == x)return x;
    return par[x] = root(par[x]);
}

void unite(int x,int y){
    x = root(x);
    y = root(y);
    par[x] = y;
}

int main(void){
    cin >> n >> m;
    
    int a[m],b[m];
    for(int i = 0;i < m;i++){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
    }
    
    int alina = 0;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++)par[j] = j;
        for(int j = 0;j < m;j++){
            if(i == j)continue;
            unite(a[j],b[j]);
        }
        
        int gray = 0;
        for(int j = 0;j < n;j++){
            for(int l = 0;l < n;l++){
                if(root(j) != root(l))gray++;
            }
        }
        if(gray)alina++;
    }
    cout << alina << endl;
}
