#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;
 
//1-origin
template <typename T>
struct FenwickTree {
        vector<T> data;
        FenwickTree(int n) : data(n + 1, 0) {}
        //data[i] += x
        void add(int i, T x){
                while (i <= (int)data.size()) {
                        data[i] += x;
                        i += i & -i;
                }
        }
        //[1, i)
        T sum(int i){
                T res = 0;
                while (i > 0) {
                        res += data[i];
                        i -= i & -i;
                }
                return res;
        }
        //[l, r)
        T sum(int l, int r) { return sum(r) - sum(l); }
};
long long InversionNumber(const vector<int> &a) {
        FenwickTree<long long> ft(300030);
        long long res = 0;
        for (int i = 0; i < a.size(); i ++) {
                res += i - ft.sum(a[i]);
                ft.add(a[i], 1);
        }
        return res;
}
 
int main() {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        rep(i, n) {
                scanf("%d", &a[i]);
        }
        long long lb = 0, ub = 1e9 + 5;
        while (ub - lb > 1) {
                long long x = (lb + ub) / 2;
                vector<int> b(n);
                rep(i, n) {
                        b[i] = a[i] >= x ? 1 : -1;
                }
                vector<int> acc(n + 1);
                for (int i = 1; i <= n; i ++) {
                        acc[i] = acc[i - 1] + b[i - 1];
                }
                rep(i, n + 1) acc[i] += 150000;
                long long res = (long long) (n + 1) * n / 2 - InversionNumber(acc);
                if (res >= ((long long) (n + 1) * n / 2 + 1) / 2) {
                        lb = x;
                } else {
                        ub = x;
                }
        }
        printf("%lld\n", lb);
        return 0;
}