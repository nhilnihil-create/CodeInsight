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

int a[N], b[N], c[N], n, memo[N][4];

int Solve(int idx, int prev){
    // 0 for a, 1 for b, 2 for c
    if(idx == n)    return 0;
    if(memo[idx][prev] != -1)   return memo[idx][prev];

    int res = -OO;
    if(prev == 0){  // The previous one was 'A'
        memo[idx][prev] = max(b[idx] + Solve(idx+1, 1), c[idx] + Solve(idx+1, 2));
    }else if(prev == 1){  // The previous one was 'b'
        memo[idx][prev] = max(a[idx] + Solve(idx+1, 0), c[idx] + Solve(idx+1, 2));
    }else if(prev == 2){  // The previous one was 'c'
        memo[idx][prev] = max(b[idx] + Solve(idx+1, 1), a[idx] + Solve(idx+1, 0));
    }else{
        memo[idx][prev] = max(max(a[idx] + Solve(idx+1, 0), b[idx] + Solve(idx+1, 1)), c[idx] + Solve(idx+1, 2));
    }
    return memo[idx][prev];
}
int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    GO();
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d %d %d", a+i, b+i, c+i);
    }
    memset(memo, -1, sizeof(memo));
    printf("%d", Solve(0, 3));
    return 0;
}