#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
using namespace std;

const int maxn = (1 << 18) + 5;

int f[maxn], s[maxn];

int a[maxn];
int n;

void init(){
    for(int i = 0;i < (1 << n);i++){
        f[i] = a[i];
        s[i] = -1;
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < (1 << n);j++){
            if(j & (1 << i)){
                int v = j ^ (1 << i);
                int u = j;
                if(f[v] > f[u]){
                    s[u] = f[u];
                    f[u] = f[v];
                }else{
                    if(f[v] > s[u]){
                        s[u] = f[v];
                    }
                } 
                if(s[v] > s[u]){
                    s[u] = s[v];
                }
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0;i < (1 << n);i++){
        scanf("%d", &a[i]);
    }
    init();
    int pre = 0;
    for(int i = 0;i < (1 << n);i++){
        pre = max(pre, f[i] + s[i]);
        if(i > 0){
            printf("%d\n", pre);
        }
    }
    return 0;
}
