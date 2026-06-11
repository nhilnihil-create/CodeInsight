#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-result"

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long long unsigned int ull;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define REPD(i, n) for (int i = 0, i##_len = (n); i < i##_len; i--)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
const int MOD = 1000000007;

void Main()
{
    int a, b, c, x;
    cin >> a >> b >> c >> x;

    int cnt = 0;
    for(int ia = 0; ia <= a; ia++){
        int ta = ia * 500;
        for(int ib = 0; ib <= b; ib++){
            int tb = ib * 100;
            for(int ic = 0; ic <= c; ic++){
                int tc = ic * 50;
                int total = ta + tb + tc;

                if(total == x)
                    cnt ++;
                
                if(total >= x)
                    break;
            }
            if(ta + tb >= x)
                break;
        }
        if(ta >= x)
            break;
    }

    cout << cnt << endl;
}

int main()
{
    std::ios::sync_with_stdio(false); // printf/scanf を使わない
    std::cin.tie(0);
    std::cout << std::fixed << std::setprecision(15); // 浮動小数点数を小数点表記

    Main();

    return 0;
}
