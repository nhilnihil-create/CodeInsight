#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <assert.h>
#include <unordered_set>



using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)








template <typename T>
class SegmentTree {
private:
    int n;    // 配列の要素数
    T init;    // 配列を初期化するときの値
    vector<T> data;     // セグメントツリーを持つ配列
public:
    SegmentTree(int m, T init = INF) : n(1), init(init){
        while(n < m) n <<= 1;
        data.assign(2 * n - 1, init);
    }
    
    T operation(T t1, T t2){
        return max(t1, t2);
    }
    
    void update(int k, T val){
        k += n - 1;
        data[k] = val;
        
        while(k > 0){
            k = (k - 1) / 2;
            data[k] = operation(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }
    
    // [a, b) の値を求める
    T query(int a, int b){
        return query(a, b, 0, 0, n);
    }
    
    ll query(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return init;
        if(a <= l && r <= b){
            return data[k];
        }
        else{
            T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return operation(vl, vr);
        }
    }
};



int main(){
    ll n, c, x[100000], v[100000];
    
    scanf("%lld %lld", &n, &c);
    REP(i, n){
        scanf("%lld %lld", &x[i], &v[i]);
    }
    
    ll sum1 = 0, sum2 = 0, mx1 = 0, mx2 = 0;
    SegmentTree<ll> s1(n, -INF), s2(n, -INF);
    REP(i, n){
        if(i == 0){
            sum1 += v[i] - x[i];
            sum2 += v[n - i - 1] - (c - x[n - i - 1]);
        }
        else{
            sum1 += v[i] - x[i] + x[i - 1];
            sum2 += v[n - i - 1] - (c - x[n - i - 1]) + (c - x[n - i]);
        }
        mx1 = max(mx1, sum1);
        s1.update(i, mx1);
        mx2 = max(mx2, sum2);
        s2.update(i, mx2);
    }
    
    ll mx3 = 0;
    sum1 = 0;
    sum2 = 0;
    REP(i, n - 1){
        if(i == 0){
            sum1 += v[i] - x[i];
            sum2 += v[n - i - 1] - (c - x[n - i - 1]);
        }
        else{
            sum1 += v[i] - x[i] + x[i - 1];
            sum2 += v[n - i - 1] - (c - x[n - i - 1]) + (c - x[n - i]);
        }
        mx3 = max(mx3, max(sum1 - x[i] + s2.query(0, n - i - 1), sum2 - (c - x[n - i - 1]) + s1.query(0, n - i - 1)));
    }
    
    printf("%lld\n", max(max(mx1, mx2), mx3));
}