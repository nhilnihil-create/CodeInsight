#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;

const int mod = 1e9 + 7;

const int N = 1005;

int n, k;
long long a[N];

long long x;

vector<long long> edge;

bool check(long long x) {
    long long ok = 0;
    for(int i = 0; i < edge.size(); i++) {
        long long ans = (edge[i] & x);
        if(ans == x)
            ok++;
    }
    if(ok >= k) return 1;
    else return 0;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++) {
        long long sum = 0;
        for(int j = i; j <= n; j++) {
            sum += a[j];
            edge.pb(sum);
        }
    }
    x = 0;
    for(int i = 60; i >= 0; i--) {
        long long y = (x | (1ll << i));
        if(check(y))
            x = y;
    }
    cout << x;
}

