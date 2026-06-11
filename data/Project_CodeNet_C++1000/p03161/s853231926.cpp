#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define loop(i, n)      for(int i = 0 ; i < n ; ++i)
#define rloop(i, n)     for(int i = int(n)-1 ; i >= 0 ; --i)
#define loopOne(i, n)   for(int i = 1 ; i <= n; ++i)
#define range(i, a, b)  for(int i = int(a) ; i <= int(b) ; ++i)
#define sz(x)   int(x.size())

void GO(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
const ll N = 1e5+100, OO = 1e9;
int mx = -OO, mn = OO;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int arr[N], n, memo[N];
int k;
int Solve(int idx){
    if(idx == n-1)    return 0;
    if(memo[idx] != -1)    return memo[idx];
    int res = OO;
    for(int i = 1; i <= k; ++i) {
        if (idx + i < n)
            res = min(res, abs(arr[idx] - arr[idx + i]) + Solve(idx + i));
        else
            break;
    }
    return memo[idx] = res;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    GO();
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i){
        scanf("%d", arr+i);
    }
    memset(memo, -1, sizeof(memo));
    printf("%d", Solve(0));
    return 0;
}