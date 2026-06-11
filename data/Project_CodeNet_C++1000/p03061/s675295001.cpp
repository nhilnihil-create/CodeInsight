#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;

template <class T>
class SegTree {
    int n;
    vector<T> data;
    T def;
    function<T(T,T)> operation;
    function<T(T,T)> update;

    T _query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return def;
        if(a <= l && r <= b) return data[k];
        else {
            T c1 = _query(a, b, 2*k+1, l, (l+r)/2);
            T c2 = _query(a, b, 2*k+2, (l+r)/2, r);
            return operation(c1, c2);
        }
    }
  public:
    SegTree(size_t _n, T _def, function<T(T,T)> _operation, function<T(T,T)> _update)
    : def(_def), operation(_operation), update(_update) {
            n = 1;
            while(n < _n) {
                n *= 2;
            }
            data = vector<T>(2*n-1, def);
    }

    void change(int i, T x) {
        i += n-1;
        data[i] = update(data[i], x);
        while(i > 0) {
            i = (i-1)/2;
            data[i] = operation(data[2*i+1], data[2*i+2]);
        }
    }

    T query(int a, int b) {
        return _query(a, b, 0, 0, n);
    }

    T operator[](int i) {
        return data[i+n-1];
    }
};

long long gcd(long long a, long long b) {
    return b ? gcd(b, a%b) : a;
}


int main() {
    int n;
    cin >> n;
    SegTree<long long> st(n, 0, [](long long a, long long b) {return gcd(a,b); },
                          [](long long a, long long b) {return b; });
    rep(i,n) {
        int a;
        cin >> a;
        st.change(i, a);
    }
    long long res = 1;
    rep(i,n) {
        long long l = st.query(0,i);
        long long r = st.query(i+1, n);
        res = max(res, gcd(l,r));
    }
    cout << res << endl;
    return 0;
}