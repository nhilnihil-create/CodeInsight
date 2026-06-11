//#include <bits/stdc++.h>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>

#define INF 100000000000
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;

int par[1000000]; //par[i] : iの親の番号

//全てが根であるとして初期化
void init(int n){
   for(int i = 0; i < n; i++){
       par[i] = i;
       //cout << i << " " << par[i] << endl;
   }
}

//データxが属する木の根を再帰で取得
int root(int x){
    //cout << x << endl;
   if(par[x] == x){
       return x;
   }else{
       return par[x] = root(par[x]);
   }
}

//xとyが同じ木に属しているかを判定
bool same(int x, int y){
   return root(x) == root(y);
}

//xとyの木を併合
void unite(int x, int y){
   int rx = root(x); //xの根
   int ry = root(y); //yの根
   if(rx == ry) return; //根が同じならそのまま

   par[rx] = ry; //根が違うなら併合
}


int main() {
    long long n, m;
    cin >> n >> m;
    init(n);
    int data[n];
    for(int i=0;i<n;i++) cin >> data[i];
    for(int i=0;i<m;i++) {
        long long a, b;
        cin >> a >> b;
        unite(a-1, b-1);
    }
    //cout << "C" << endl;
    long long ans = 0;


    for(int i=0;i<n;i++) {
        if(same(i, data[i]-1)) ans+=1;
    }
    cout << ans << endl;
}