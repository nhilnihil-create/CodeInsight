#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int N, A, B, C;
vec<int> l(8);

int dfs(int now, int a, int b, int c) {
    if(now == N){
        if(a==0 || b == 0 || c == 0) return 99999999;
        else return abs(A-a) + abs(B-b) + abs(C-c) - 30;
    }
    int ans1 = dfs(now+1,a+l[now],b,c) + 10;
    int ans2 = dfs(now+1,a,b+l[now],c) + 10;
    int ans3 = dfs(now+1,a,b,c+l[now]) + 10;
    int ans0 = dfs(now+1,a,b,c);
    return min({ans0,ans1,ans2,ans3});
}

int main() {
    cin >> N >> A >> B >> C;
    rep(i, N) cin >> l[i];
    cout << dfs(0,0,0,0) << endl;
}
