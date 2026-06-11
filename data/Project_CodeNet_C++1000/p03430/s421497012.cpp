//
//  main.hpp
//  HelloWorld
//
//  Created by Vipul Sharma on 2/17/18.
//  Copyright © 2018 Vipul Sharma. All rights reserved.
//  vipsharmavip@gmail.com [' . '] :)

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<algorithm>
#include<cstdio>
#include<stack>
#include<queue>
#include<cstring>
#define up 1
#define right 2
#define down 3
#define left 4
#define mod 1000000007
#define ll long long

using namespace std;

string x;
int k;
int dp[300][300][301];

int go(int i, int j, int k){
    if(i > j) return 0;
    if(i == j) return 1;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    int ans = 0;
    if(x[i] == x[j])  ans = 2 + go(i + 1, j - 1, k); else
    {
        ans = max(go(i + 1, j, k), go(i, j - 1, k));
        if(k)
            ans = max(ans, 2 + go(i + 1, j - 1, k - 1));
    }
    return dp[i][j][k] = ans;
}

int main(){
    
    cin.sync_with_stdio(false);
    cin >> x >> k;
    memset(dp, -1, sizeof dp);
    cout << go(0, x.size() - 1, k);
}
