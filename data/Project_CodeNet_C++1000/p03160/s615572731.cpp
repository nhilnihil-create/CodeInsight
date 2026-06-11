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

int arr[N], n, memo[N], res;

int Solve(int idx){

    if(memo[idx] != -1)    return memo[idx];
    int op1 = OO, op2 = OO;
    if(idx + 1 >= n)    return 0;
    op1 = abs(arr[idx]-arr[idx+1]) + Solve(idx+1);
    if(idx + 2 < n)
        op2 = abs(arr[idx]-arr[idx+2]) + Solve(idx+2);

    return memo[idx] = min(op1, op2);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    GO();
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", arr+i);
    }
    memset(memo, -1, sizeof(memo));
    printf("%d", Solve(0));
    return 0;
}