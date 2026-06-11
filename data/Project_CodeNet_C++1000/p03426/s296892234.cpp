#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int H, W, D;
    cin >> H >> W >> D;

    map<int ,P> m;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            int a;
            cin >> a;
            m[a] = make_pair(i, j);
        }
    }

    map<int, int> sum;
    for(int i=1; i<=H*W; i++){
        if(sum.count(i) != 0) continue;

        int now = i;
        sum[now] = 0;
        P prev = m[now];
        now += D;
        while(now <= H*W){
            P next = m[now];
            sum[now] += sum[now-D] + abs(prev.first-next.first) + abs(prev.second-next.second);
            prev = next;
            now += D;
        }
    }

    int Q;
    cin >> Q;
    int ans[Q];
    for(int i=0; i<Q; i++){
        int l, r;
        cin >> l >> r;
        ans[i] = sum[r] - sum[l];
    }

    for(int i=0; i<Q; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
