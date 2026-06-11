#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int> P;
map<P, long long> m;
vector<P> place;
int D;
long long INF = 1e18;
int main(){
    int H, W;
    cin >> H >> W >> D;
    vector<vector<int>> A(H, vector<int> (W));
    vector<P> place(H * W);
    for(int i= 0; i < H; i++){
        for(int j = 0; j < W; j++) {
            cin >> A[i][j];
            place[A[i][j] - 1] = P(i, j);
        }
    }
    vector<long long> vec[D];
    for(int i = 0; i < D; i++){
        long long t = i;
        long long res = 0;
        while(t + D <= H * W){
            vec[i].push_back(res);
            P v = place[t], u = place[t + D];
            t += D;
            res += abs(v.first - u.first) + abs(v.second - u.second);
        }
        vec[i].push_back(res);
    }
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int L, R;
        cin >> L >> R;
        int s = R % D;
        long long ans;
        if(s != 0) ans = vec[s - 1][(R - s) / D] - vec[s - 1][(L - s) / D];
        else ans = vec[D - 1][(R - s) / D - 1] - vec[D - 1][(L - s) / D - 1];
        cout << ans << endl;
    }
}