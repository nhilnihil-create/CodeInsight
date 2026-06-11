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

void solve(long long K){
    int a = 1;
    while(K>0){
        cout << a << endl;
        double mn = 1e15;
        int na = -1;
        int d = 1;
        while(a * 10 >= d) {
            int t = (a / d + 1) * d + d - 1;
            double sn = f(t);
            if (sn < mn) {
                na = t;
                mn = sn;
            }
            d *= 10;
        }
        a = na;
        --K;
    }
}

signed main(){
    long long K;
    scanf("%lld",&K);
    solve(K);
    return 0;
}