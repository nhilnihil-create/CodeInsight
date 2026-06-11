#include <bits/stdc++.h>
#define SLBIT __builtin_popcount

using namespace std;

const int oo = 1e9;
const int N = 5e5 + 100;
const int di[] = {-1,0,1,0};
const int dj[] = {0,1,0,-1};

typedef pair<int,int> i2;
typedef pair<int,i2> i3;
typedef pair<long long,int> i2ll;

int n;
long long C;
long long A[N],T[N],F1[N],F2[N],DP1[N],DP2[N];
int B[N];
void nhap()
{
    cin >> n >> C;
    for (int i = 1; i <= n; i++) {
        cin >> A[i] >> B[i];
    }
}

void solve() {
    long long Res = 0;
    long long Tong = 0;
    for (int i = 1; i <= n; i++) {
        Tong += 1ll * B[i];
        F1[i] = Tong - A[i];
        DP1[i] = max(DP1[i - 1],F1[i]);
    }
    Tong = 0;
    for (int i = n; i >= 1; i--) {
        Tong += 1ll * B[i];
        F2[i] = Tong - (C - A[i]);
        DP2[i] = max(DP2[i + 1],F2[i]);
    }
    Res = max(Res,DP1[n]);
    Res = max(Res,DP2[1]);
    for (int i = 1; i < n; i++) {
        Res = max(Res,F1[i] - A[i] + DP2[i + 1]);
    }
    for (int i = n; i > 1; i--) {
        Res = max(Res,F2[i] - (C - A[i]) + DP1[i - 1]);
    }
    cout << Res;
}
int main()
{
    nhap();
    solve();
}
