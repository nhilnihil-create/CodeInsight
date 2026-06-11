#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int H, W, D;
    cin >> H >> W >> D;

    int A[H][W];
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> A[i][j];
        }
    }

    int Q;
    cin >> Q;
    int L[Q], R[Q];
    for(int i=0; i<Q; i++) cin >> L[i] >> R[i];

    map<int, P> m;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            m[A[i][j]] = P(i, j);
        }
    }

    int sum[H*W+1];
    fill(sum, sum+H*W+1, -1);
    for(int i=1; i<=H*W; i++){
        if(sum[i] != -1) continue;
        sum[i] = 0;
        // cout << "---- " << i << endl;
        for(int j=i+D; j<=H*W; j+=D){
            P now = m[j];
            P prev = m[j-D];
            sum[j] = sum[j-D] + abs(now.first-prev.first) + abs(now.second-prev.second);
            // cout << "prev " << prev.first << " " << prev.second << endl;
            // cout << "now " << now.first << " " << now.second << endl;
        }
    }

    for(int i=0; i<Q; i++){
        if(sum[L[i]] == 0) cout << sum[R[i]] << endl;
        else cout << sum[R[i]] - sum[L[i]] << endl;
    }

    return 0;
}
