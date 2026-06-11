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

const int maxn = 1e5 + 5;

int n;
int a[maxn];
int b[maxn], m;

typedef long long LL;
int c[maxn];
int pre[maxn];
int d[maxn * 2];

void add(int p, int c){
    for(int i = p;i < maxn * 2;i += i & -i){
        d[i] += c;
    }
}

int sum(int p){
    int ret = 0;
    for(int i = p;i > 0;i -= i & -i){
        ret += d[i];
    }
    return ret;
}
LL cal(int val){
    //memset(d, 0, sizeof(d));
    c[0] = 0;
    for(int i = 1;i <= n;i++){
        if(a[i] >= val)
            c[i] = 1;
        else
            c[i] = -1;
    }
    pre[0] = 0;
    add(pre[0] + maxn, 1);
    for(int i = 1;i <= n;i++){
        pre[i] = pre[i - 1] + c[i];
        add(pre[i] + maxn, 1);
    }
    long long ans = 0;
    for(int i = 0;i <= n;i++){
        add(pre[i] + maxn, -1); 
        ans += sum(maxn * 2 - 1) - sum(pre[i] + maxn - 1);
    } 
    return ans;
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    m = unique(b + 1, b + 1 + n) - b - 1;
    int l = 1, r = m;
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(cal(b[mid]) >= 1LL * n * (n + 1) / 4){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    cout << b[l] << endl;
    return 0;
}
