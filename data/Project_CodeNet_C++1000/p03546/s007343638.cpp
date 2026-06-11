#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<int>> c(10, vector<int> (10));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> c[i][j];
        }
    }

    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }

    vector<int> a(10, 0);
    int tmp;
    for (int i = 0; i < H*W; i++) {
        cin >> tmp;
        if(tmp == -1) continue;
        a[tmp]++;
    }

    ll ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += c[i][1] * a[i];
    }

    // for (int i = 0; i < 10; i++) {
    //     printf("%d %d\n", c[i][1], a[i]);
    // }
    printf("%lld\n", ans);
}