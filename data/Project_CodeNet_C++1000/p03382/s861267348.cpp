#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef pair<int, int> P;
#define REP(i, x, n) for(lint i = x ; i < n ; i++)
#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for(lint i = n - 1 ; i >= 0 ; i--)
#define SORT(c) sort((c).begin(), (c).end())

const int IINF = 1e9 + 10;
const lint LLINF = (lint)1e18 + 10;
const lint MOD = (lint)1e9 + 7;
const lint inv = MOD - 2;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

int main(){
    int n;
    scanf("%d", &n);
    vector<double> a(n);
    rep(i, n){
        scanf("%lf", &a[i]);
    }
    SORT(a);
    int ans1 = a[n-1], ans2 = a[0];
    double tmp = abs(a[0] - a[n-1]/2.0);
    rep(i, n-1){
        if(tmp > abs(a[i] - a[n-1]/2)){
            ans2 = a[i];
            tmp = abs(a[i] - a[n-1]/2);
        }
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}