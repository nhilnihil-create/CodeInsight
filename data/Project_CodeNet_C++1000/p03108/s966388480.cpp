#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
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

using LONG = long long;
using LVEC = vector<long long>;

#define FOR(_i, s, e) for(_i = s; _i < e; ++_i)
#define FOR_INV(_i, s, e) for(_i = e - 1; _i >= s; --_i)

long long PRIME = 1e9 + 7;
long long PRIME2 = 998244353;


using pos = std::pair<LONG, LONG>;


class UnionFindTree{
public:
    UnionFindTree(LONG N){
        ranks.resize(N, 1);
        nums.resize(N, 1);
        parent.resize(N, -1);
    }

    LONG merge(LONG a, LONG b){
        LONG r_a = _root(a);
        LONG r_b = _root(b);

        if(r_a == r_b){
            return 0;
        }

        LONG ret = nums[r_a] * nums[r_b];

        if(ranks[r_a] < ranks[r_b]){
            parent[r_b] = r_a;
            ranks[r_a] = ranks[r_b] + 1;
            nums[r_a] += nums[r_b];
        }
        else{
            parent[r_a] = r_b;
            ranks[r_b] = ranks[r_a] + 1;
            nums[r_b] += nums[r_a];
        }

        return ret;
    }

    bool isSame(LONG a, LONG b){
        LONG r_a = _root(a);
        LONG r_b = _root(b);

        return r_a == r_b;
    }

private:
    vector<LONG> ranks;
    vector<LONG> nums;
    vector<LONG> parent;

    LONG _root(LONG a){
        if(parent[a] == -1){
            return a;
        }

        LONG r = _root(parent[a]);
        parent[a] = r;
        return r;
    }
};


int main(){
    LONG N, M;
    cin >> N >> M;

    UnionFindTree tree(N);
    LONG i;

    LVEC A(M), B(M);
    FOR(i, 0, M){
        cin >> A[i] >> B[i];
    }

    LVEC result(M + 1, 0);
    result[M] = N * (N - 1) / 2;
    FOR_INV(i, 0, M){
        LONG merge_num = tree.merge(A[i]-1, B[i]-1);
        result[i] = result[i+1] - merge_num;
        if(result[i] == 0){
            break;
        }
    }

    FOR(i, 0, M){
        cout << result[i + 1] << endl;
    }
}


