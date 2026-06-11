#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
#define P pair<int, int>
int N , A , B , C ;
vector<int>L;
const int MAX_N = 8;
int l[MAX_N];
int dfs(int num, int a, int b, int c, int cost){
    if(num == N){
        if(a==0 || b==0 || c==0) return 1000000009;
        else return abs(a-A)+abs(b-B)+abs(c-C) + cost;
    }
 
    int ret0 = dfs(num+1, a, b, c, cost);
    int ret1 = dfs(num+1, a+l[num], b, c, cost+10);
    int ret2 = dfs(num+1, a, b+l[num], c, cost+10);
    int ret3 = dfs(num+1, a, b, c+l[num], cost+10);
 
    int ret = min(ret0, ret1);
    ret= min(ret, ret2);
    ret = min(ret, ret3);
 
    return ret;
}


int main () {
    cin >> N >> A >> B >> C;
 
    for(int i=0; i<N; i++){
        cin >> l[i];
    }
 
    int ans = dfs(0,0,0,0,-30);
 
    cout << ans << endl;
    

    return 0 ;
}

 
