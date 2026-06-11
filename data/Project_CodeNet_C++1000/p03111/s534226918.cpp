#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int N, A, B, C;
vector<int> l;
int dfs(int a, int b, int c, int now){
    if(now==N){
        if(a==0||b==0||c==0) return 1000000000;
        return abs(A-a)+abs(B-b)+abs(C-c);
    }
    int r1=dfs(a, b, c, now+1);
    int r2=dfs(a+l[now], b, c, now+1)+10;
    int r3=dfs(a, b+l[now], c, now+1)+10;
    int r4=dfs(a, b, c+l[now], now+1)+10;
    return min({r1,r2,r3,r4});
}
int main() {
    cin >> N >> A >> B >> C;
    l.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> l[i];
    }
    int ans = dfs(0, 0, 0, 0)-30;
    cout << ans << endl;
}