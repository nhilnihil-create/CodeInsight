#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;


// 1-indexed
class FenwickTree {
    long long n;
    vector<long long> a;
public:
    FenwickTree(long long n) : n(n), a(n+1, 0) {}
    long long get(long long i) {
        long long sm = 0;
        for(; i > 0; i -= i&-i) sm += a[i];
        return sm;
    }
    void set(long long i, long long x) {
        for(; i <= n; i += i&-i) a[i] += x;
    }
    long long at(long long i){return get(i) - get(i-1);}
};


// 順序を保存したまま圧縮する
// ex) 1,5,8,8,2,4 -> 1,4,5,6,2,3 
void compress(vector<long long> &a){
    auto b = a;
    sort(b.begin(), b.end());
    map<long long, long long> mp;
    long long num = 1;
    for(auto x : b){
        if(mp[x] == 0)
            mp[x] = num;
        num++;
    }
    for(auto &x : a)
        x = mp[x]++;
}

// バブルソートの交換回数 (反転数、転倒数、inversion)
// 1~n からなる vector を与えて 1,2,...,n にソートする交換回数
// <=> i < j, a[i] > a[j] となる組の数
// 今までに出現した数以下に1を足しながら左から順に見ていけば良い
long long inversion(const vector<long long> &a){
    long long N = a.size();
    long long ans = 0;
    FenwickTree ft(N);
    for(long long i=0; i<N; i++){
        ans += i - ft.get(a[i]);
        ft.set(a[i], 1);
    }
    return ans;
}

bool judge(vector<long long> &a, long long x){
    long long N = a.size();
    vector<long long> b(N), c(N+1, 0);

    for(long long i=0; i<N; i++)
        b[i] = (a[i] <= x) ? 1 : -1;

    for(long long i=1; i<=N; i++)
        c[i] = c[i-1] + b[i-1];

    for(long long i=1; i<=N; i++)
        c[i] = -c[i];


    compress(c);

    long long inv = inversion(c);

    return inv >= N*(N+1)/4+1;
}

int main(){
    long long N;
    cin >> N;
    vector<long long> a(N);
    for(long long i=0; i<N; i++) cin >> a[i];

    if(N == 1){
        cout << a[0] << endl;
        return 0;
    }

    vector<long long> b = a;
    b.push_back(-1);
    sort(b.begin(), b.end());

    long long lb = 0, ub = N;
    while(ub - lb > 1){
        long long mid = (lb + ub) / 2;
        if(judge(a, b[mid])) ub = mid;
        else lb = mid;
    }
    cout << b[ub] << endl;

    return 0;
}