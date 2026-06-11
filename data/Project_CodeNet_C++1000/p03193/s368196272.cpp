#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    int N, H, W, ans = 0;
    cin >> N >> H >> W;
    for (int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        if (a >= H && b >= W){
            ans++;
        }
    }
    cout << ans << endl;
}

