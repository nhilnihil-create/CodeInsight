#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string.h>
#include <stack>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    ll ans = 0;
    rep(x,0,N+1){
        rep(y, 0, N+1){
            int tmp = N - R*x - G*y;
            if(tmp >= 0 && tmp %B==0){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}