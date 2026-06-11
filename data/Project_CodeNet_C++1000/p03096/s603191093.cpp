/// wa ^3^

#pragma GCC optimize("O3")

#include<iostream>
#include<vector>
                           
using namespace std;

const int MOD = 1e9 + 7;

int cnt[(int)2e5+10];

int main() {
    int n;
    scanf("%d", &n);
    int dp = -1;
    vector<int> a;
    for (int x; n--;) {
        scanf("%d", &x);
        if (x != dp)
            a.push_back(x);
        dp = x;            
    }
    dp = 1;
    for (int x : a) {
        cnt[x] += dp;
        if (cnt[x] >= MOD)
            cnt[x] -= MOD;
        dp = cnt[x];    
    }
    printf("%d", dp);
    return 0;
}

