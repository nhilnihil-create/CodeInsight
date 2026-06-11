#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct BIT {
    int n;
    vector<T> dat;

    BIT(int n=0){
        initialize(n);
    }

    void initialize(int nin){
        n = nin;
        dat.resize(n, 0);
    }

    T sum(int i){
        T s = 0;
        while(i >= 0){
            s += dat[i];
            i = (i & (i+1)) - 1;
        }
        return s;
    }

    T sum_between(int i, int j){
        return sum(j) - sum(i-1);
    }

    void plus(int i, T x){
        while(i < n){
            dat[i] += x;
            i |= i+1;
        }
    }

    // a[0]+...+a[ret] >= x
    int lower_bound(T x){
        int ret = -1;
        int k = 1;
        while(2*k <= n) k <<= 1;
        for( ;k>0; k>>=1){
            if(ret+k < n && dat[ret+k] < x){
                x -= dat[ret+k];
                ret += k;
            }
        }
        return ret + 1;
    }
};

int N, A[100000];

bool check(int X){
    BIT<int> bit(2*N+1);
    int64_t res = 0, s = N;
    bit.plus(s, 1);
    for(int i=0; i<N; i++){
        s += (A[i] <= X ? -1 : 1);
        res += bit.sum_between(s+1, 2*N);
        bit.plus(s, 1);
    }
    int64_t need = int64_t(N) * (N+1) / 4 + 1;
    return (res >= need);
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    int ok = 1e9, ng = 0;
    while(ok-ng>1){
        int mid = (ok+ng)/2;
        (check(mid) ? ok : ng) = mid;
    }
    cout << ok << endl;
}