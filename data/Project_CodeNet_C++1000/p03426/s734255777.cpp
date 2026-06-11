#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>
#include <set>
#include <numeric>

using namespace std;

template <typename T>
using TABLE = vector<vector<T>>;

long long PRIME = 1e9 + 7;
long long PRIME2 = 998244353;

struct info{
    info(){

    }

    long long A;
    int x, y;

    long long cost(const info& other){
        return abs(x - other.x) + abs(y - other.y);
    }
};


int main(){
    long long W, H, D;
    cin >> H >> W >> D;
    long long area = W * H;

    vector<info> masu(area);
    for(int y = 0, index = 0; y < H; ++y){
        for(int x = 0; x < W; ++x, ++index){
            long long A;
            cin >> A;

            masu[index].A = A;
            masu[index].x = x;
            masu[index].y = y;
        }
    }

    sort(masu.begin(), masu.end(), [](const info& l, const info& r){return l.A < r.A;});
    vector<long long> energy_sum(area, 0);

    for(int i = D; i < area; ++i){
        energy_sum[i] = energy_sum[i - D] + masu[i].cost(masu[i-D]);
    }

//    for(int i = 0; i < area; ++i){
//        cout << energy_sum[i] << " ";
//    }
//    cout << endl;

    long long Q;
    cin >> Q;

    vector<long long> results(Q);
    long long L, R;

    for(int i = 0; i < Q; ++i){
        cin >> L >> R;
        results[i] = energy_sum[R - 1] - energy_sum[L - 1];
    }

    for(int i = 0; i < Q; ++i){
        cout << results[i] << endl;
    }
}
