#include<bits/stdc++.h>
using namespace std;

long long int K;

template<size_t mx>
struct SnukeNumber{
    long long int ans[mx];
    long double a, b;

    constexpr long long int dsum(long long a){
        long long ret = 0;
        while(a){
            ret += a % 10;
            a /= 10;
        }
        return ret;
    }

    constexpr long double f(long long a){
        long long ret = dsum(a);
        return a / static_cast<long double>(ret);
    }

    constexpr SnukeNumber() : ans(), a(f(1)), b(){
        size_t cnt = 0;
        long long int s = 1, t = 1;
        for(long long int i = 1; cnt < mx; i += s){
            b = f(i + s);
            if(a < b){
                s = t;
                b = f(i + s);
            }
            if(a > b){
                if(s == t)t *= 10;
            }else{
                ans[cnt] = i;
                ++cnt;
            }
            long double tmp = a;
            a = b;
            b = tmp;
        }
    }
};

constexpr SnukeNumber<792> S = SnukeNumber<792>();

int main(){
    scanf("%lld", &K);
    for(int i = 0; i < K; ++i)printf("%lld\n", S.ans[i]);
    return 0;
}