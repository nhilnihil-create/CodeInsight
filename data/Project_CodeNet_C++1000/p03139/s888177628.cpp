#include<bits/stdc++.h>
#define LL long long
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPA(i,n) for(int i=1;i<(n);++i)
#define PII pair<int,int>
#define PLI pair<long long, int>
#define PLL pair<long long, long long>
#define PDD pair<double, double>
#define MOD ((int)1e9 + 7)
#define INF ((int)1e9)
#define INFLL ((LL)1e18)
#define ALL(x) (x).begin(),(x).end()
#define ctoi(x) (x - 'a') 
#define CTOI(x) (x - 'A')
#define BIT(x) (1 << (x))
using namespace std;

LL modinv(LL a){
    LL b = MOD, u = 1, v = 0;
    while(b){
        LL t = a / b;
        a -= t * b;swap(a, b);
        u -= t * v;swap(u, v);
    }
    u%=MOD;
    if(u < 0) u += MOD;
    return u;

}

LL exp(LL a, LL b){
    LL res = 1;
    LL sum = a;
    while(b){
        if(b&1)res = (res * sum);
        sum = (sum * sum);
        b>>=1;
    }
    return res;
}

double exp(double a, LL b){
    double res = 1;
    double sum = a;
    while(b){
        if(b&1)res = (res * sum);
        sum = (sum * sum);
        b>>=1;
    }
    return res;
}

signed  main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << min(b, c) << " " << max(0, b + c - a) << endl;
    return 0;
}
