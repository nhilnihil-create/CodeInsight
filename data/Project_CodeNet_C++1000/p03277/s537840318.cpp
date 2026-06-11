#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long
const double eps = 1e-9;

template<typename T>
struct Fenwick{
    vector<T> bit;
    T mod;
    Fenwick(int n){
        bit = vector<T>(n + 1);
        mod = 0;
    }
    void add(int i, T v){
        int n = bit.size();
        ++i;
        while(i < n){
            bit[i] += v;
            if(mod > eps) bit[i] %= mod;
            i += i & -i;
        }
    }
    T get(int i){
        T res = 0;
        ++i;
        while(i > 0){
            res += bit[i];
            if(mod > eps) bit[i] %= mod;
            i -= i & -i;
        }
        return res;
    }
};

bool judge(vector<long long> &a, long long c) {
    int N = a.size();
    vector<int> b(N + 1);
    for(int i = 0; i < N; ++i) {
        b[i + 1] = a[i] >= c ? 1: -1;
        b[i + 1] += b[i];
    }
    Fenwick<int> bit(2 * N + 10);
    const int OFFSET = N + 5;
    int cnt = 0;
    for(int i = 0; i <= N; ++i) {
        cnt += bit.get(b[i] + OFFSET);
        bit.add(b[i] + OFFSET, 1);
    }
    return cnt * 2 >= N * (N + 1) / 2;
}

void solve(long long N, std::vector<long long> a){
    int l = 0, u = (int)1e10;
    while(u - l > 1) {
        int c = (l + u) / 2;
        if (judge(a, c)) {
            l = c;
        } else {
            u = c;
        }
    }
    cout << l << endl;
}

signed main(){
	ios::sync_with_stdio(false);
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, std::move(a));
    return 0;
}