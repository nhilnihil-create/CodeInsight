#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm> // sort
#include <math.h>

#define DEBUG 0

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll mod = 1000000007;
static const ll INF = 1000000000000000000LL;
                    //999999997000000003
                    //1000000000000000000

using namespace std;

//3 3 1
//
//111 0
//112 1
//113 0
//121 2
//122 1
//123 2
//131 0
//132 1
//133 0
//211 1
//212 2
//213 1
//221 1
//222 0
//223 1
//231 1
//232 2
//233 1
//311 0
//312 1
//313 0
//321 2
//322 1
//323 2
//331 0
//332 1
//333 0
//
//24/27
//
//2値が隣あって出現する確率  
//全部6回ずつ 11,12,13,21,22,23,31,32,33
//6 * 9 = 54
//d = 1になるのは、
//6 * 4 = 24

//d = 0なら、n個
//i - d > 0 なら++
//i + d <= N なら++

int main(){
#if DEBUG
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    ll n,m,d;
    cin >> n >> m >> d;

    //全通り -> nのm乗

    //2値の組み合わせ -> n * n;
    //2値の組合わせ1つあたりの出現回数-> n^(m-2)
    
    //答えとなる組み合わせ 
    ll kumi = 0;
    if(d == 0)kumi = n;
    else
    {
        for(ll i = 1; i <= n; ++i)
        {
            if(i - d >= 1)++kumi;
            if(i + d <= n)++kumi;
        }
    }

    //2値の組合わせ1つあたりの出現回数
    //ll kaisu = pow(n,m-2) * (m-1);

    //kekka  =  kumi * n^(m-2) / n ^ m
    //=  kumi / n^n

    double res;
    res = (double)(m-1) * (double)kumi;

    //cout << kumi << endl;
    //cout << kaisu << endl;


    ll cnt = 0;
    //while(cnt < m)
    while(cnt < 2)
    {
        ++cnt;
        res /= double(n);
    }

    printf("%.12f\n",res);

    return 0;
}
