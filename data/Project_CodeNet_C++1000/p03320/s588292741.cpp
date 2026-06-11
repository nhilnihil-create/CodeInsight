#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

double f(int K) {
    double t = K;
    int s = 0;
    while(K > 0) {
        s += K % 10;
        K /= 10;
    }
    return t / s;
}

double func(int s, int d, double t, vector<long long> &v) {
    double u = f(s);

    if (s == 98LL) {
        cerr << "pass" << s << "," << u << "," << t << endl;
    }
    if (u > t) {
        return t;
    }

    v.push_back(s);

    double r = u;

    if (d >= 10) {
        int e = s - d / 10;
        r = min(r, func(e, d / 10, r, v));
    }


    if (s - d > 0) {
        int w = s - d;
        r = min(r, func(w, d, r, v));
    }

    return r;
}

vector<int> res;

void solve(long long K){
    vector<int> v;

    int d = (int)1e15;
    func(d - 1, d / 10, d, v);
//    for(int k = 1; k < 15; ++k) {
//        cerr << k << "," << v.size() << endl;
//        double t = f(d - 1);
//        func(d - 1, d / 10, t, v);
//        d *= 10;
//    }
    sort(ALL(v));
    for(int i = 0; i < res.size(); ++i) {
        if (res[i] != v[i]) {
            cout << res[i] << " " << v[i] << endl;
            break;
        }
    }
    for(int i = 0; i < K; ++i) {
        cout << v[i] << endl;
    }
}

signed main(){
    for(int i = 1; i < 1000; ++i) {
        bool b = true;
        double s = f(i);
        for(int j = i + 1; j <= i * 10; ++j) {
            b = b && s <= f(j);
        }
        if (b) {
            res.push_back(i);
            cerr << i << " " << s << endl;
        }
    }

    long long K;
    scanf("%lld",&K);
    solve(K);
    return 0;
}