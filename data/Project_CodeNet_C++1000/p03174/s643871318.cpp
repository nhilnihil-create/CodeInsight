#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef bitset<22> MASK;
#define ll long long
#define PI 3.14159265359
#define x first
#define y second
#define point pair<int,int>
#define clr(x, val)	memset((x), (val), sizeof(x))

//you don't know math, unless you can do math!
int n;
int a[25][25];

int dp[25][2100000];
int mod = 1e9 + 7;
int solve(int i, MASK mask){
    if(i == n)
        return 1;

    int &ret = dp[i][mask.to_ulong()];
    if(ret != -1)
        return ret;

    ret = 0;
    for(int k = 0; k < n; k++){
        if(!a[i][k] || mask[k])
            continue;

        MASK msk = mask;
        msk[k] = 1;
        ret = (ret + solve(i + 1, msk))%mod;
    }

    return ret;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    clr(dp, -1);
    cin>>n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>a[i][j];


    cout<<solve(0, 0);
}
