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

const int maxn = 2e5 + 5;

int a[maxn], b[maxn];
int c[maxn], d[maxn];
int n;

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    } 
    for(int i = 1;i <= n;i++){
        scanf("%d", &b[i]);
    }
    long long ans = 0;
    for(int j = 0;j <= 28;j++){
        int mask = (1 << (j + 1)) - 1;
        int l1 = (1 << j);
        int r1 = mask;
        int l2 = (1 << (j + 2)) - (1 << j);
        int r2 = (1 << (j + 2)) - 1;
        for(int i = 1;i <= n;i++){
            c[i] = a[i] & mask; 
            d[i] = b[i] & mask;
        }
        sort(d + 1, d + 1 + n);
        long long count = 0;
        for(int i = 1;i <= n;i++){
            count += upper_bound(d + 1, d + 1 + n, r1 - c[i]) - lower_bound(d + 1, d + 1 + n, l1 - c[i]);
            count += upper_bound(d + 1, d + 1 + n, r2 - c[i]) - lower_bound(d + 1, d + 1 + n, l2 - c[i]);
        }
        if(count & 1){
            ans |= (1 << j);
        }
    }
    cout << ans << endl;
    return 0;
}
