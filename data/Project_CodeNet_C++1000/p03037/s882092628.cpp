#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <map>
#include <stdio.h>
#include <string.h>


#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using namespace std;

int main() {
    //ios::sync_with_stdio(false);
    //std::cin.tie(nullptr);

    int n, m;
    int l[100001], r[100001];
    int mem[100001];
    int ans = 0;
    int count = 0;

    memset(mem,0,sizeof(mem));

    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        cin >> l[i] >> r[i];
    }

    for(int i = 0; i < m; i ++){
        count ++;
        for(int j = l[i]; j <= r[i]; j ++){
            mem[j]  ++;
        }
    }

    for(int i = 1; i <= n; i ++){
        if(mem[i] == m) ans ++;
    }
    cout << ans;

    return 0;
}

