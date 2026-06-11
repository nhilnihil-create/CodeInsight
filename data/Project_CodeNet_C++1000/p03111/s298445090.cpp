#include <bits/stdc++.h>
using namespace std;

int N, A, B, C;
int l[8];

int dfs(int cur, int a, int b, int c)
{
    if(cur == N){
        if(min({a,b,c}) > 0){
            return abs(a-A) + abs(b-B) + abs(c-C) - 30;
        }else{
            return 1e9+7;
        }
    }
    int ret0 = dfs(cur+1, a, b, c);
    int ret1 = dfs(cur+1, a+l[cur], b, c) + 10;
    int ret2 = dfs(cur+1, a, b+l[cur], c) + 10;
    int ret3 = dfs(cur+1, a, b, c+l[cur]) + 10;
    return min({ret0, ret1, ret2, ret3});
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> A >> B >> C;

    for(int i=0; i<N; i++){
        cin >> l[i];
    }

    cout << dfs(0,0,0,0) << endl;
    return 0;
}
